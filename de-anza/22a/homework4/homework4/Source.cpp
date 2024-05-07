/*
Author: Caitlin Tram
Homework 4
This program displays the number of days in a month of a given year.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int month, year, numDays;

    cout << "Enter a year and a month number (1-12) separated by spaces:\n";
    cin >> year >> month;

    if (month >= 1 && month <= 12)
    {
        {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                numDays = 31;
                cout << "There are " << numDays << " days in " << month << "/" << year << endl;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                numDays = 30;
                cout << "There are " << numDays << " days in " << month << "/" << year << endl;
            }
        }
        if (month == 2)
        {
            if (year >= 1582)
            {
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    numDays = 29;
                    cout << "There are " << numDays << " days in " << month << "/" << year << endl;
                }
                else if ((year % 100 == 0) || (year % 4 != 0)) {
                    numDays = 28;
                    cout << "There are " << numDays << " days in " << month << "/" << year << endl;
                }
            }
            else {
                numDays = 28;
                cout << "There are " << numDays << " days in " << month << "/" << year << endl;
            }

        }
    }
    else
        cout << "Invalid month!" << endl;

    return 0;
}