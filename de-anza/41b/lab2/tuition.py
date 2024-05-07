import csv
import numpy as np
import matplotlib.pyplot as plt


class Tuition: 
    def __init__(self): 
        self.yearsFile = "years.csv"
        self.costsFile = "costs.csv"
        self.statesFile = "states.csv"
        self.years = []
 
        statesInitial = np.loadtxt(self.statesFile, str, delimiter=",")       
        
        with open (self.yearsFile, "r") as f: 
            reader = csv.reader(f)
            row = next(reader)
            for yearRange in row:
                year = yearRange.split("-")
                self.years.append(year[0])
            

        costsInitial = np.loadtxt(self.costsFile, int, delimiter = ",")

        self.states = np.delete(statesInitial,[1])
        self.costs = np.delete(costsInitial, 1, axis=0)

    def tuitionDistribution(self):
        plt.hist(self.costs[0:self.costs.shape[0], 18], bins = 10, color = ["red"], edgecolor = "black")
        plt.title("Tuition Distribution")
        plt.xlabel("Tuition")
        plt.ylabel("Frequency")

    def lowestTuitionStates(self, numStates):
        currentTuition = {self.costs[state, 18]: self.states[state] for state in range(self.costs.shape[0])}
        for k in sorted(currentTuition.keys())[:numStates]:
            plt.bar(currentTuition[k], k, color = "red", edgecolor = "black")
        plt.xticks(rotation = 45, ha = "right")
        plt.title("Lowest Tuition States")
        plt.xlabel("State")
        plt.ylabel("Tuition")

        return currentTuition[sorted(currentTuition.keys())[0]]

    def tuitionTrend(self):
        tuitionChanges = self.costs[:, -1] - self.costs[:, 0]
        highest = tuitionChanges.argsort()[-5:][::-1]
        lowest = tuitionChanges.argmin()
        maxStates = self.states[highest]
        minState = self.states[lowest]

        for i, state in enumerate(maxStates):
            plt.plot(self.years, self.costs[highest[i]], label=state)
        plt.plot(self.years, self.costs[lowest], label=minState)
        plt.title('5 Most Increased Tuition States and 1 Lowest')
        plt.xticks(rotation = 45, ha = "right")
        plt.xlabel('Year')
        plt.ylabel('Tuition')
        plt.legend()

        return maxStates[0]

    def tuitionStats(self):
        currentTuition = self.costs[:, -1]
        minTuition = int(round(currentTuition.min()))
        maxTuition = int(round(currentTuition.max()))
        meanTuition = int(round(currentTuition.mean()))
        medianTuition = int(round(np.median(currentTuition)))
        return (minTuition, maxTuition, meanTuition, medianTuition)

