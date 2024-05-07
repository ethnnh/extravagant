/*
Author: Ethan Hernandez
homework6.cpp
This program will generate a random number for you to guess between 1-10
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;

int main() {
    //Variables 
    int choice = 1, totalGames = 0, totalWins = 0, totalLosses = 0, attempt, answer;
    bool gameOver = false;

    //Seeding rand
    srand(time(0));
    
    cout << "Welcome to the number guessing game!\n"; //Displays first time message 
    cout << "For each game, you have at most 3 chances to guess a secret number from 1 to 10.\n";

    while (choice != 0) { // 0 as a sentinel
        cout << "\nEnter a number from 1 to 10. Enter 0 to exit: ";
        cin >> choice; //first input
        answer = rand() % 10 + 1; //generates random number
        attempt = 1;
        gameOver = false; // boolean variable to control the for loop
        for (; !gameOver; attempt++) { //loop for input validation
            if (choice == 0) {
                gameOver = true;
            }
            else if (choice == answer) {
                cout << "Congratulations, correct! Let's start a new secret number.\n";
                totalWins++;
                totalGames++;
                gameOver = true;
            }
            else if (attempt == 3 && choice != answer) {
                cout << "Not correct. You have reached your third trial. The correct number is  " << answer << ".\n";
                cout << "Let's start a new secret number.\n";
                totalLosses++;
                totalGames++;
                gameOver = true;
            }
            else if (choice != answer) {
                cout << "Not correct, try again: ";
                cin >> choice;
            }
        }
    }
    //displays game summary if user enters 0
    cout << "Game Summary: \n";
    cout << setw(18) << left << "Total games:" << setw(7) << right << totalGames << endl;
    cout << setw(18) << left << "Total game wins:" << setw(7) << right << totalWins << endl;
    cout << setw(18) << left << "Total game losses:" << setw(7) << right << totalLosses << endl;

    return 0;
}