/*
Author: Ethan Hernandez
exercise4.cpp
This program generates a random number within a given range.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //Variables
    int highNum,
        lowNum,
        randNum;
    //Asks user for the range of the random number
    cout << "This program generates a random number within a range [low, high]\n";
    cout << "Enter the low and high value separated by a space: ";
    cin >> lowNum >> highNum;
    cout << endl;

    //Checks if numbers for range are valid, if they are valid then display random number.
    if (highNum < lowNum)
        cout << "The high value must be > low value." << endl;

    else if (lowNum < 0 || highNum < 0)
        cout << "The low and high value must be > 0" << endl;

    else if (highNum > lowNum && highNum > 0 && lowNum > 0)
        {
            srand(time(0));
            randNum = lowNum + (rand() % (highNum - lowNum + 1));
            cout << "The random number is " << randNum << endl;
        }

    else
        cout << "Invalid, try again.\n";
   
   
    return 0;
}

