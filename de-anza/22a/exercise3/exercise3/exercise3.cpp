/*
Author: Ethan Hernandez
exercise3.cpp
This program will show the formatted date when given a month year and day as inputs.
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //Variables
    string year;
    string month;
    string day;
    string dateString;

    //Asks user for year, month, and day
    cout << "My name is Ethan Hernandez" << "\n\n";
    cout << "Enter a year number (YYYY): ";
    cin >> year;
    cout << "Enter a month name (i.e. January, February, ...): ";
    cin >> month;
    cout << "Enter a day number (DD): ";
    cin >> day;
    cout << '\n';

    //Returns the formatted date, as well as the length in characters of the date output string
    dateString = "The formatted date is '" + month + " " + day + ", " + year + "'.";
    cout << dateString << endl;
    cout << "The total output text length is " << dateString.length() << ".\n";

    return 0;
}


