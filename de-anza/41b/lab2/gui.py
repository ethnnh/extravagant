import tkinter as tk
from tkinter import ttk
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
from tuition import Tuition


class MainWindow(tk.Tk):
    def __init__(self, tuition):
        super().__init__()
        self.title("Tuition")
        self.tuition = tuition
        self.currentTuition = self.tuition.tuitionStats()
        self.createWidgets()

    def createWidgets(self):
        explanation = "Yearly College Tuition"
        explanationLabel = tk.Label(
            self, text=explanation, font=("Arial", 12))
        explanationLabel.pack(padx=10, pady=10)

        buttonsFrame = tk.Frame(self)
        buttonsFrame.pack()

        overviewButton = ttk.Button(
            buttonsFrame, text="Overview", command=self.showOverviewPlot)
        overviewButton.pack(side=tk.LEFT, padx=5, pady=5)

        lowestCostButton = ttk.Button(
            buttonsFrame, text="Lowest Cost", command=self.showLowestCostDialog)
        lowestCostButton.pack(side=tk.LEFT, padx=5, pady=5)

        largestChangeButton = ttk.Button(
            buttonsFrame, text="Largest Change", command=self.showLargestChangePlot)
        largestChangeButton.pack(side=tk.LEFT, padx=5, pady=5)

        tuitionStatsFrame = tk.Frame(self)
        tuitionStatsFrame.pack(padx=10, pady=10)

        tk.Label(tuitionStatsFrame, text="Lowest Tuition: $" + str(self.currentTuition[0]),
                 font=("Arial", 10), fg="green").grid(row=0, column=0, padx=10, pady=5)
        tk.Label(tuitionStatsFrame, text="Highest Tuition: $" + str(self.currentTuition[1]),
                 font=("Arial", 10), fg="green").grid(row=0, column=1, padx=10, pady=5)
        tk.Label(tuitionStatsFrame, text="Mean Tuition: $" + str(self.currentTuition[2]),
                 font=("Arial", 10), fg="green").grid(row=1, column=0, padx=10, pady=5)
        tk.Label(tuitionStatsFrame, text="Median Tuition: $" + str(self.currentTuition[3]),
                 font=("Arial", 10), fg="green").grid(row=1, column=1, padx=10, pady=5)

    def showOverviewPlot(self):
        plotWindow = PlotWindow(self.tuition)
        plotWindow.plotOverview()

    def showLowestCostDialog(self):
        dialogWindow = DialogWindow(self)

    def showLowestCostPlot(self, numStates):
        plotWindow = PlotWindow(self.tuition)
        plotWindow.plotLowestCost(numStates)

    def showLargestChangePlot(self):
        plotWindow = PlotWindow(self.tuition)
        plotWindow.plotLargestChange()

class PlotWindow:
    def __init__(self, tuition):
        self.tuition = tuition

    def plotOverview(self):
        tuitionDistribution = self.tuition.tuitionDistribution()
        plt.show()

    def plotLowestCost(self, numStates):
        lowestTuitionState = self.tuition.lowestTuitionStates(numStates)
        plt.show()

    def plotLargestChange(self):
        maxTuitionState = self.tuition.tuitionTrend()
        plt.show()


class DialogWindow(tk.Toplevel):
    def __init__(self, parent):
        super().__init__(parent)
        self.title("Lowest Cost")
        self.parent = parent
        self.withdraw()
        self.geometry("300x250")
        self.resizable(width=False, height=False)
        self.protocol("WM_DELETE_WINDOW", self.cancel)

        self.choice = tk.StringVar(value="5")

        tk.Label(self, text="Select number of states:").pack(
            side=tk.TOP, padx=10, pady=10)
        for i in [5, 10, 15, 20]:
            tk.Radiobutton(self, text=str(i), variable=self.choice,
                           value=str(i)).pack(side=tk.TOP, padx=10, pady=5)

        lockButton = ttk.Button(
            self, text="Click to Lock in Selection", command=self.lock)
        lockButton.pack(side=tk.TOP, padx=10, pady=10)

        closeButton = ttk.Button(self, text="Close", command=self.cancel)
        closeButton.pack(side=tk.BOTTOM, padx=10, pady=10)

        self.transient(parent)
        self.deiconify()
        self.grab_set()
        parent.wait_window(self)

    def lock(self):
        numStates = int(self.choice.get())
        self.parent.showLowestCostPlot(numStates)
        self.destroy()

    def cancel(self):
        self.parent.focus_set()
        self.destroy()

if __name__ == "__main__":
    tuition = Tuition()
    app = MainWindow(tuition)
    app.mainloop()
