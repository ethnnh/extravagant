'''
Ethan Hernandez & Caitlin Tram
Lab 3
'''

import csv

RAINFALL = 'rainfall.csv'
WATERSHEDS = 'city.txt'
LABOUTPUT = 'lab3out.txt'

def readData() :
  waterDict = {}
  with open(WATERSHEDS) as cities: 
    Lines = cities.readlines()
    for line in Lines:
      line = line.strip().split(": ")
      waterDict[line[0]] = line[1]
  print(waterDict)

  rainfallDict = {}
  with open(RAINFALL) as rainfalls :
    reader = csv.reader(rainfalls)
    for line in reader :
      if line[2] not in rainfallDict :
        rainfallDict[line[2]] = {}
      rainfallDict[line[2]][line[0]] = line[1]
  print(rainfallDict)
  
  print("Read in data for ", end = "")
  [print(k, end = " ") for k in waterDict]

  return waterDict, rainfallDict

    
def singleShed(shed, waterDict, rainfallDict) :
    print("Sensors for", shed, "watershed, which includes: ")
    [print(v, end = "") for v in waterDict[shed]]
    for k, v in rainfallDict[shed].items():
        print(f"{k:<20} {v:>20}")


def averageShed(rainfallDict) :
    averageDict = {}
    for outerKey in rainfallDict.keys() :
        avg = 0
        count = 0
        for v in rainfallDict[outerKey].values() :
            avg += v
            count += 1 
        avg = avg / count
        averageDict[avg] = outerKey
    print(f"{'Watershed':<20} {'Inches':>20}")
    for k in sorted(averageDict, reverse = True) :
        print(f"{averageDict[k]:<20} {k:>20}")

def highestSensors(n, rainfallDict) :
    sensorDict = {}
    for k in rainfallDict.keys() :
        for k, v in rainfallDict[k].items() :
            sensorDict[v] = k
    if n > 0 :
        for k in sorted(sensorDict, reverse = True)[:n]:
            print(sensorDict[k], ": ", k, sep = "")
     
def saveData() :

def userChoice(x = 0) :
    choice = int(input("Enter choice: "))
    if x == 0 :
        while choice not in range(1, 5) :
            choice = int(input("Enter choice 1-4: "))
    else :
        while choice not in range(1, 6) :
            choice = x[int(input("Enter choice 1-5: ")) - 1]
    return choice

def main() :
    waterDict, rainfallDict = readData()
    print("1. Data for one watershed")
    print("2. Watershed by average rainfall")
    print("3. Max sensors")
    print("4. Quit")
    choice = userChoice()
    if choice == 1 :
        keyList = list(waterDict.keys())
        for i in range(1, 6) :
            print(i, ". ", keyList[i-1], sep = "") 
        singleShed(userChoice(keyList), waterDict, rainfallDict)
    elif choice == 2 :
        averageShed(rainfallDict) 
    elif choice == 3 :
        highestSensors(n, rainfallDict)
    else :

if __name__ == "__main__":
  main()