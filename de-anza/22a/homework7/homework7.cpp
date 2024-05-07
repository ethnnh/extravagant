/*
Author: Ethan Hernandez
homework7.cpp
This program will generate random numbers based on the vowel inputted by the user
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//prototype for random function
int createRandomFromChar(char inputChar);

int main() {
    //variables
    char in1, in2, in3, in4, in5, ans = 'y';
    //seeding rand function
    srand(time(0));
    
    cout << "This program plays a simple random number game.\n";
    //while user chooses to replay
    while (ans == 'y' || ans == 'Y') {
        cout << "Enter 5 vowel characters (a,e,i,o,u or A,E,I,O,U) separated by spaces: ";
        cin >> in1 >> in2 >> in3 >> in4 >> in5; //takes user input for vowels
        //calls random function using each user input as a parameter, then displays results
        cout << "\nThe random numbers are ";
        cout << createRandomFromChar(in1) << ' ';
        cout << createRandomFromChar(in2) << ' ';
        cout << createRandomFromChar(in3) << ' ';
        cout << createRandomFromChar(in4) << ' ';
        cout << createRandomFromChar(in5) << endl;
        cout << "\nDo you want to play another game? (Y or y to continue): "; //asks user if they would like to play again
        cin.ignore();
        cin.get(ans);
    }
    cout << "Goodbye";
    return 0;
}
//random function
int createRandomFromChar(char inputChar) {
    //local variable for number
    int n;
    //if else if for vowels input by user
    if (inputChar == 'a' || inputChar == 'A') {
        n = (rand() % 20) + 1;
    }
    else if (inputChar == 'e' || inputChar == 'E') {
        n = (rand() % 20) + 21;
    }
    else if (inputChar == 'i' || inputChar == 'I') {
        n = (rand() % 20) + 41;
    }
    else if (inputChar == 'o' || inputChar == 'O') {
        n = (rand() % 20) + 61;
    }
    else if (inputChar == 'u' || inputChar == 'U') {
        n = (rand() % 20) + 81;
    }
    else {
        n = 0;
    }
    //returns result
    return n;
    cout << "hi";
}