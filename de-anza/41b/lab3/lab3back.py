from bs4 import BeautifulSoup
import requests
import json
import sqlite3

CITIES_TO_SCRAPE = ['San Jose', 'Cupertino']
URL = 'https://guide.michelin.com/us/en/california'
class Scraper :
    def __init__(self) :
        for self.scrapeCity in CITIES_TO_SCRAPE :
            self.scrapeCity = self.scrapeCity.replace(' ', '-')
            print(self.scrapeCity)
            self.url = f"{URL}/{self.scrapeCity.lower()}/restaurants"
            self.page = requests.get(self.url)
            self.soup = BeautifulSoup(self.page.content, "lxml")
            self.scrapeCityDict = {}
            if self.soup.find('ul', {'class' : 'pagination'}) :
                for link in self.soup.select('ul.pagination li a')[:-1] :
                    self.url = f"https://guide.michelin.com{link['href']}"
                    self.page = requests.get(self.url)
                    self.soup = BeautifulSoup(self.page.content, "lxml")
                    self._getData()
            else : 
                self._getData()
            with open (f"{self.scrapeCity}.json", 'w') as f :
                json.dump(self.scrapeCityDict, f, indent = 4)
            
    def _getData(self) :
        restaurants = self._getRestaurants()
        for restaurant in restaurants :
            self._getRestaurantData(restaurant)

    def _getRestaurants(self) :
        names = []
        for name in self.soup.select('a.link.with-love') :
            names.append(name['aria-label'].strip('Open '))
        return(names)
    
    def _getRestaurantData(self, name) :
        for div in self.soup.select('div.col-md-6.col-lg-4.col-xl-3') :
            if div.find('a', {'aria-label' : f'Open {name}'}) :
                url = (f"https://guide.michelin.com{div.find('a')['href']}")
                city = div.find('div', {'class' : 'card__menu-footer--location'}).text.rsplit(', ', 1)[0].strip()
                cost = (div.find(
                    'div', {'class': 'card__menu-footer--price'}).text.split()[0].strip())
                cuisine = div.find(
                    'div', {'class': 'card__menu-footer--price'}).text.rsplit('·', 1)[1].strip()
                page = requests.get(url)
                soup = BeautifulSoup(page.content, "lxml")
                address = soup.find('li', {'class' : 'restaurant-details__heading--address'}).text
                self.scrapeCityDict[name] = {'url' : url, 'city' : city, 'cost' : cost, 'cuisine' : cuisine, 'address' : address}
                
class Database : 
    def __init__(self) : 
        self.conn = sqlite3.connect('restaurants.db')
        self.cur = self.conn.cursor()
        self.cur.execute('CREATE TABLE IF NOT EXISTS Restaurants (name TEXT, url TEXT, city TEXT, cost TEXT, cuisine TEXT, address TEXT)')
        self.conn.commit()
        self.conn.close()

    def insert(self, name, url, city, cost, cuisine, address) :
        self.conn = sqlite3.connect('restaurants.db')
        self.cur = self.conn.cursor()
        self.cur.execute('INSERT INTO Restaurants VALUES (?, ?, ?, ?, ?, ?)', (name, url, city, cost, cuisine, address))
        self.conn.commit()
        self.conn.close()

    def select(self) :
        self.conn = sqlite3.connect('restaurants.db')
        self.cur = self.conn.cursor()
        self.cur.execute('SELECT * FROM Restaurants')
        rows = self.cur.fetchall()
        self.conn.close()
        return(rows)


test = Scraper()