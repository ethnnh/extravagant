#include <iostream>
#include <cmath>

using namespace std;
// Function prototypes
int getRootCount(double& discriminant, double coefficients[]);
void solveEquation(double discriminant, double coefficients[], double roots[]);

int main() {
    // Variables
    int const SIZE = 3;
    double coefficients[SIZE];
    double discriminant;
    // Prompt the user for 3 input numbers
    cout << "This program solves quadratic formulas\n";
    cout << "Enter 3 coefficients separate by spaces: ";
    // Store the user inputs in an array named coefficients with a size of 3
    cin >> coefficients[0] >> coefficients[1]  >> coefficients[2] ;
    // Added a while loop that ends when the user enters 0 0 0 as their 3 inputs
    while (coefficients[0] !=0 || coefficients[1] != 0 || coefficients[2] != 0) {
        // If first input is 0 the formula does not work, so ask the user for another 3 numbers
        if (coefficients[0]  == 0) // If first input is 0 the formula does not work, so ask the user for another 3 numbers
            cout << "First coefficient cannot be 0." << endl;
        else //If first coefficient is not 0
        {
            // Get number of roots using function getRootCount()
            int rootCount = getRootCount(discriminant, coefficients);
            if (rootCount == 0)   // No root
                cout << "There is no root" << endl;
            else   // 1 or 2 roots
            {
                double roots[2]; // Array for roots
                solveEquation(discriminant, coefficients,  roots); // Call function solveEquation to determine the value of the root(s)
                if (rootCount == 1) // If there is only one root, then display first number in the array
                    cout << "There is one root: " << roots[0] << endl;
                else // If there is two roots, then display both numbers in the array
                    cout << "There are 2 roots: " << roots[0] << "   " << roots[1] << endl;
            }
        }
        // Prompt user for 3 inputs again
        cout << "Enter 3 coefficients separate by spaces: ";
        cin >> coefficients[0] >> coefficients[1]  >> coefficients[2];
    }
    return 0;
}
/* Function to determine the number of roots, if any, using the discriminant formula
* Discriminant variable is passed by reference so that solveEquation() function can later use the value
*/
int getRootCount(double& discriminant, double coefficients[]) {
    discriminant = pow(coefficients[1], 2) - 4 * coefficients[0] * coefficients[2];
    if (discriminant < 0) { // If the discriminant is less than 0 there are no roots
        return 0;
    }
    else if (discriminant == 0) { // If the discriminant is exactly 0 then there is one root
        return 1;
    }
    else { // If the discriminant is greater than 0 then there is two roots
        return 2;
    }
}
/* Function to determine the value of the roots if there are any
* After determining the value of the roots, the function stores the values in the array roots[]
*/
void solveEquation(double discriminant, double coefficients[], double roots[]) {
    if (discriminant == 0) { // If there is only one root, then use the appropriate formula and store the value in the first number in roots[]
        roots[0] = (-coefficients[1]) / (2 * coefficients[0]); 
    }
    else { // If there are two roots, then use the appropriate formula and store both values in roots[]
        roots[0] = ((-coefficients[1]) + sqrt(discriminant)) / (2 * coefficients[0]);
        roots[1] = ((-coefficients[1]) - sqrt(discriminant)) / (2 * coefficients[0]);
    }
}