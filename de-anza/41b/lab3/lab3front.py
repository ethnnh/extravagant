import tkinter as tk
from tkinter import messagebox
import sqlite3


class MainWindow(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)
        self.title('Restaurant Search')
        self.geometry('300x200')

        tk.Label(self, text='Search for restaurants by:').pack()

        self.btn_city = tk.Button(self, text='City', command=self.city_search)
        self.btn_city.pack()

        self.btn_cuisine = tk.Button(
            self, text='Cuisine', command=self.cuisine_search)
        self.btn_cuisine.pack()

    def city_search(self):
        self.btn_city['state'] = 'disabled'
        self.btn_cuisine['state'] = 'disabled'
        CityDialog(self)

    def cuisine_search(self):
        self.btn_city['state'] = 'disabled'
        self.btn_cuisine['state'] = 'disabled'
        CuisineDialog(self)


class DialogWindow(tk.Toplevel):
    def __init__(self, master):
        tk.Toplevel.__init__(self, master)
        self.geometry('300x200')
        self.protocol('WM_DELETE_WINDOW', self.close)

    def close(self):
        self.master.btn_city['state'] = 'normal'
        self.master.btn_cuisine['state'] = 'normal'
        self.destroy()


class CityDialog(DialogWindow):
    def __init__(self, master):
        DialogWindow.__init__(self, master)
        # add the listbox of cities and other components here
        # ...


class CuisineDialog(DialogWindow):
    def __init__(self, master):
        DialogWindow.__init__(self, master)
        # add the listbox of cuisines and other components here
        # ...


class DisplayWindow(tk.Toplevel):
    def __init__(self, master, restaurant):
        tk.Toplevel.__init__(self, master)
        self.title('Restaurant Details')
        self.geometry('300x200')
        # display restaurant details here
        # ...


def main():
    try:
        # try to open the database file here
        # ...
        app = MainWindow()
        app.mainloop()
    except Exception as e:
        messagebox.showerror('Error', 'Unable to open the database file.')
        # end the app


if __name__ == '__main__':
    main()
