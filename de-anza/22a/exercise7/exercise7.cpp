/*
Author: Ethan Hernandez
exercise7.cpp
This program will return the sum of the squares of given numbers as long as the number is not greater than 100
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;
//function prototypes for square and print functions
int sumOfSquares(int, int = 0, int = 0);
void print(string, int); 

int main()
{
    int sum;
    cout << "Program output:\n\n";
    sum = sumOfSquares(1, 2, 3);
    print("1- The value of sumOfSquares(1, 2, 3)  is  ", sum);
    sum = sumOfSquares(1, 2);
    print("2- The value of sumOfSquares(1, 2) is      ", sum);
    sum = sumOfSquares(3);
    print("3- The value of sumOfSquares(3) is         ", sum);
    sum = sumOfSquares(101);
    print("4- The value of sumOfSquares(101) is       ", sum);
    sum = sumOfSquares(1, 101);
    print("5- The value of sumOfSquares(1, 101) is    ", sum);
    sum = sumOfSquares(1, 4, 101);
    print("6- The value of sumOfSquares(1, 4, 101) is ", sum);
 
    return 0;
}

int sumOfSquares(int num1, int num2, int num3) {
    int x; //value that will be returned to main
    if (num1 > 100 || num2 > 100 || num3 > 100) { //checks if any of the integers are > 100, if they are then x = -1
        x = -1;
    }
    else { //if all integers are valid, then square the integers and set x equal to the sum of those squares
        x = pow(num1, 2) + pow(num2, 2) + pow(num3, 2);
    }
    return x; //return x
}

void print(string text, int number) { //print function
    cout << text << setw(5) << right << number << endl; //display the text string along with the number, format the number nicely to the right side
}