/* 
Author: Ethan Hernandez
homework2.cpp
This program will calculate the quotients(both integer and floating-point) and remainder of two numbers.
*/ 



#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Variables
	int num1, num2;

	//Describes program's purpose to user, prompts them, and stores their input.
	cout << "This program calculates quotient and remainder of two numbers.\n";
	cout << '\n';
	cout << "Enter two whole numbers separated by a space: ";
	cin >> num1 >> num2;
	cout << '\n';
	
	//Outputs all results using the two numbers previously provided by the user.
	cout << "The quotient of integer division (" << num1 << "/" << num2 << ") is: " << num1 / num2 << endl;
	cout << "The remainder of integer division (" << num1 << "/" << num2 << ") is: " << num1 % num2 << endl;
	cout << setprecision(9) << fixed;
	cout << "The result of floating-point division (" << num1 << "/" << num2 << ") is: " << static_cast<double>(num1) / num2 << endl;
	
	return 0;
}


