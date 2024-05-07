/*
*Author: Ethan Hernandez
*exercise8.cpp
*This program will ask the user to enter up to 20 numbers, then it will display the facts about the numbers based on if they are even or odd.
*/
#include <iostream>
#include <string>
#include <climits>
#include <iomanip>

using namespace std;

int main() {
    //Variables
    const int NUM_AMOUNT = 20;
    int inputNums[NUM_AMOUNT];
    int input, 
        evenMax = INT_MIN, 
        oddMax = INT_MIN, 
        evenSum = 0, 
        oddSum = 0, 
        index = 0;
    //Program explanation    
    cout << "This program asks you to enter up to 20 whole numbers, then it displays interesting facts\n";
    //String for the prompt to reduce redundancy in the program
    string prompt = "Enter a number, or enter -999 when there is no more: ";
    //Prompts user for input
    cout << prompt;
    cin >> input; 
    //Stores inputs into the array until either the user enters -999 or the max amount of numbers(20) is reached
    while (input != -999 && index < NUM_AMOUNT) {
        inputNums[index] = input; //Stores the input of the user at the given index
        index++; //Increments the index for the next number to be stored
        cout << prompt; //Prompts user again for new input
        cin >> input;          
    }

    cout << '\n';
    //List of even numbers
    cout << setw(23) << left << "List of even numbers: ";
    //Loop iterates through each number that the user has given
    for (int i = 0; i < index; i++) {
        if (inputNums[i] % 2 == 0) { //Determines whether the given number is even
            evenSum += inputNums[i]; //If it is even, it adds it to the sum of even numbers
            cout << setw(5) << inputNums[i]; //Outputs any even numbers
            if (inputNums[i] > evenMax) { //Determines whether the even number is the highest one yet
                evenMax = inputNums[i]; //If it is the highest, store in evenMax
            }
        }
    }
    
    cout << '\n';
    //List of odd numbers
    cout << setw(23) << left << "List of odd numbers: ";
    //Loop iterates through each number that the user has given
    for (int i = 0; i < index; i++) { 
        if (inputNums[i] % 2 != 0) { //Determines whether the given number is odd
            oddSum += inputNums[i]; //If it is odd, it adds it to the sum of odd numbers
            cout << setw(5) << inputNums[i]; //Outputs any odd numbers
            if (inputNums[i] > oddMax) { //Determines whether the odd number is the highest one yet
                oddMax = inputNums[i]; //If it is the highest, store in oddMax
            }
        }
    }
    cout << "\n\n";

    if (index == 0) { //If there are no numbers in the array, end the program
        return 0;
    }
    //Displays both of the total sums(even and odd)
    cout << setw(30) << left << "Total sum of even numbers is " << setw(5) << right << evenSum << endl;
    cout << setw(30) << left << "Total sum of odd numbers is " << setw(5) << right << oddSum << "\n\n";
    //Determines if there are any even numbers
    if (evenMax != INT_MIN) {
        //Outputs the largest even number
        cout << setw(30) << left << "The largest even number is " << setw(5) << right << evenMax << endl;     
    }
    //Determines if there are any odd numbers
    if (oddMax != INT_MIN) {
        //Outputs the largest odd number
        cout << setw(30) << left << "The largest odd number is " << setw(5) << right << oddMax << endl;
    }
    
    return 0;
}