#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool isoscelesTriangleHeightAndArea(double, double, double&, double&);

int main() {
    double base, hypotenuse, height, area;

    cout << "This program calculates the height and the area of an isosceles triangle\n";

    cout << "\nEnter the base and side length of triangle separated by spaces, or enter 0 0 to exit: ";
    cin >> base >> hypotenuse;

    while (base != 0 || hypotenuse != 0) 
    {
        bool success = isoscelesTriangleHeightAndArea(base, hypotenuse, height, area);
        if (!success) {
            cout << "Invalid input!\n";
            base = 0, hypotenuse = 0;
        }
        else {
            cout << setw(20) << left << "Triangle height is" << setw(10) << left << height << endl;
            cout << setw(20) << left << "Triangle area is" << setw(10) << left << area << endl;
        }
        cout << "\nEnter the base and side length of triangle separated by spaces, or enter 0 0 to exit: ";
        cin >> base >> hypotenuse;
    }
  
    return 0;
}

bool isoscelesTriangleHeightAndArea(double base, double hypotenuse, double &height, double &area) {
    if (pow(hypotenuse, 2) - .25 * pow(base, 2) < 0 || base < 0 || hypotenuse < 0) {
        return false;
    }
    else {
        height = sqrt(pow(hypotenuse, 2) - .25 * pow(base, 2));
        area = .5 * base * height;
        return true;
    }
}