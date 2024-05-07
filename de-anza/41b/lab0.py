# Lab 0: Review CIS 41A
# Name: Ethan Hernandez


import csv


class Cities:
    """
    Class to read in data from the file and store it
    """

    def __init__(self, filename):
        self.data = {}
        try:
            with open(filename, 'r') as csvfile:
                reader = csv.reader(csvfile)
                for row in reader:
                    city, pop_2000, pop_2010, pop_2020 = row
                    self.data[city] = {2000: int(pop_2000), 2010: int(
                        pop_2010), 2020: int(pop_2020)}
        except FileNotFoundError:
            print("Error: Input file not found")
            exit()

    def printYear(self, year):
        """
        Class to print the population of the cities in a given year
        """
        if year not in [2000, 2010, 2020]:
            print(f"{year} is not a valid census year")
            return

        print(f"Year {year}")
        for city, pops in self.data.items():
            print(f"{city:15} {pops[year]}")


def main():
    cities = Cities("cities.csv")
    cities.printYear(2020)
    cities.printYear(2000)
    cities.printYear(10)
    cities.printYear("a")


if __name__ == "__main__":
    main()
