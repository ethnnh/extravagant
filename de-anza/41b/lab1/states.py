# states.py
from states import States
import csv


class States:
    default_filename = "statesPop.csv"

    def __init__(self, filename=None):
        if filename is None:
            filename = self.default_filename
        self._read_data(filename)

    def _read_data(self, filename):
        self.data = []
        with open(filename, newline='') as csvfile:
            reader = csv.reader(csvfile)
            next(reader)  # Skip header
            for row in reader:
                state = row[0]
                populations = list(map(int, row[1:5]))
                growth_rate = float(row[5])
                self.data.append((state, *populations, growth_rate))

    @property
    def max_states(self):
        return len(self.data)

    def _log(func):
        def wrapper(*args, **kwargs):
            with open("logfile.txt", "a") as log_file:
                log_file.write(func.__name__ + "\n")
            return func(*args, **kwargs)
        return wrapper

    @_log
    def by_pop(self, year):
        year_idx = {1990: 1, 2000: 2, 2010: 3, 2020: 4}
        if year not in year_idx:
            return None
        return sorted(self.data, key=lambda x: x[year_idx[year]], reverse=True)

    @_log
    def growth(self, positive=True):
        for state, _, _, _, _, growth_rate in self.data:
            if positive and growth_rate > 0:
                yield state, growth_rate
            elif not positive and growth_rate < 0:
                yield state, growth_rate

    @_log
    def drop(self, start_year, end_year):
        year_idx = {1990: 1, 2000: 2, 2010: 3, 2020: 4}
        if start_year not in year_idx or end_year not in year_idx:
            return None
        start_idx, end_idx = year_idx[start_year], year_idx[end_year]
        return any(x[end_idx] < x[start_idx] for x in self.data)
