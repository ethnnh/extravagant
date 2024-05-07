class UI:
    def __init__(self):
        try:
            self.states = States()
        except FileNotFoundError:
            while True:
                filename = input("Enter an input filename: ")
                try:
                    self.states = States(filename)
                    break
                except FileNotFoundError:
                    print(f"File '{filename}' not found. Please try again.")

    def by_pop(self):
        year = self.get_year()
        if year is None:
            return
        num_states = self.get_num_states()
        if num_states is None:
            return
        print(f"\nTop {num_states} most populous states in {year}:")
        state_gen = self.states.by_pop(year)
        for _ in range(num_states):
            state, pop = next(state_gen)
            print(f"{state} {pop:,}")

    def by_growth(self):
        positive = self.get_positive_or_negative()
        if positive is None:
            return
        state_gen = self.states.growth(positive)
        print("\nStates with {} growth in 2021:".format(
            "positive" if positive else "negative"))
        for state, growth in state_gen:
            print(f"{state} {growth:.1f}%")

    def check_drop(self):
        start_year = self.get_year()
        if start_year is None:
            return
        end_year = self.get_year()
        if end_year is None:
            return
        drop = self.states.drop(start_year, end_year)
        print(
            f"\n{'Population drop' if drop else 'No population drop'} between {start_year} and {end_year}")

    def main_menu(self):
        print("\n1. View most populous states")
        print("2. View growth in 2021")
        print("3. Check population drop")
        print("4. Quit")
        choice = input("Enter your choice: ")
        return choice.strip()

    def run(self):
        handlers = {
            "1": self.by_pop,
            "2": self.by_growth,
            "3": self.check_drop,
        }
        while True:
            choice = self.main_menu()
            if choice == "4":
                break
            if choice in handlers:
                handlers[choice]()
            else:
                print("Invalid choice")

    def get_year(self):
        while True:
            year = input("Enter year: ")
            if year.isdigit() and int(year) in {1990, 2000, 2010, 2020}:
                return int(year)
            else:
                print("Invalid year")

    def get_num_states(self):
        while True:
            num_states = input("Enter number of states: ")
            if num_states.isdigit():
                num_states = int(num_states)
                max_states = self.states.max_states
                if num_states > max_states:
                    num_states = max_states
                return num_states
            else:
                print("Invalid number")

    def get_positive_or_negative(self):
        while True:
            choice = input("Choose growth (p for positive, n for negative): ")
            if choice.lower() == "p":
                return True
            elif choice.lower() == "n":
                return False
            else:
                print("Invalid choice")


if __name__ == "__main__":
    UI().run()
