/*
Author: Ethan Hernandez
homework4.cpp
This program calculates and displays the number of days in a given month.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Variables and output string
    int month = 0, year = 0, days = 0;

    //Asks user for year and month
    cout << "Enter a year and a month number (1-12) separated by spaces:\n";
    cin >> year >> month;
    
    //Determines whether the given date is within a leap year or not
    if (month >= 1 && month <= 12) 
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            days = 31;
        //Leap Year Check
        else if (month == 2)
        {
            if (year >= 1582)
            {
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                    days = 29;
                else
                    days = 28;
            }
            else
                days = 28;
        }
        else
            days = 30;
        //Output
        cout << "There are " << days << " days in " << month << "/" << year;
    }
    //Alternate output incase of error
    else
        cout << "Invalid month!";
    return 0;
}