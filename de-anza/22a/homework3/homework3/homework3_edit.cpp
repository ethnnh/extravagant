/*Author: Ethan Hernandez
* homework3.cpp
* This program calculates the focus, area, and circumference of an ellipse.
*/


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    //Variables
    const double MY_PI = 3.1415926535;
    double
        focus,
        area,
        circumference,
        h,
        majorRadius,
        minorRadius;
    //Describes program
    cout << setprecision(10) << fixed;
    cout << "This program calculates the focus, area, and circumference of an ellipse.\n";
    cout << "The value used for PI is " << MY_PI << '\n' << '\n';

    //Takes and stores input from user
    cout << "Enter the semi-major axis value: ";
    cin >> majorRadius;
    cout << "Enter the semi-minor axis value: ";
    cin >> minorRadius;
    cout << '\n';

    //Calculations
    h = (majorRadius - minorRadius) / (majorRadius + minorRadius);
    focus = sqrt(pow(majorRadius, 2) - pow(minorRadius, 2));
    area = MY_PI * majorRadius * minorRadius;
    circumference = MY_PI * (majorRadius + minorRadius) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));

    //Outputs the results of the above calculations
    cout << setw(30) << left << "The ellipse focus is: ";
    cout << setw(15) << right << focus << '\n';
    cout << setw(30) << left << "The ellipse area is: ";
    cout << setw(15) << right << area << '\n';
    cout << setw(30) << left << "The ellipse circumference is: ";
    cout << setw(15) << right << circumference << '\n';
    
    return 0;
}

