/*
*Author: Ethan Hernandez
*exercise5.cpp
*This program will display all numbers divisible by a certain divisor starting from 10. 
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    //Variables
    const int 
    maxRange = 500,
    minRange = 10;
    int divisor, range, counter = 0, sum = 0, lineCount = 0;
    double avg;
    //Gets user input for divisor
    cout << "This program displays all numbers divisible by a certain divisor starting from 10.\n";
    cout << "\nEnter a divisor from 2 to 10: ";
    cin >> divisor;
    while (divisor < 2 || divisor > 10) { //Input validation
        cout << "Input " << divisor << " is not in the range of 2 to 10.\n";
        cout << "Enter a divisor from 2 to 10: ";
        cin >> divisor;  
    }
    //Gets user input for the max range
    cout << "Enter the largest number to be gernerated. It must be in the range of " << minRange << "-" << maxRange << ": ";
    cin >> range;
    while (range < minRange || range > maxRange) { //Input validation
        cout << "Input " << range << " is not in the range of " << minRange << "-" << maxRange << endl;
        cout << "Enter the largest number to be gernerated. It must be in the range of " << minRange << "-" << maxRange << ": ";
        cin >> range;
    }
    //Displays all numbers divisible by the given divisor while keeping a count and a running sum
    cout << "Generated numbers divisible by " << divisor << "from " << minRange << " to " << range << ": \n";
    for (int n = 10; n <= range; n++) {
        if (n % divisor == 0) {
            cout << setw(6) << right << n;
            counter++;
            sum += n;
            lineCount++;
        }
        if (lineCount == 15) {
            cout << endl;
            lineCount = 0;
        }
    }
    cout << "\n\n";
    //Displays total sum and count
    cout << setw(12) << left << "Total sum: " << setw(6) << right << sum << endl;
    cout << setw(12) << left << "Count: " << setw(6) << right << counter << endl;
    //Calculates average and displays it
    avg = static_cast<double>(sum) / counter;
    cout << setw(12) << left << "Average: " << setw(6) << right << avg << endl;

    return 0;
}