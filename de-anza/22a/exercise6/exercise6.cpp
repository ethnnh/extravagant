/*
Author: Ethan Hernandez
exercise6.cpp
This program will read a file of numbers then return the maximum and minimum values, along with the average.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <climits>

using namespace std;

int main() {
    //Variables
    ifstream inputFile;
    string fileName, header;
    int n, count = 0, sum = 0, max = INT_MIN, min = INT_MAX;
    double avg;
    //asks for name of file
    cout << "This program reads a file of numbers, then calculates and displays some statistics of the numbers.\n";
    cout << "Enter a file name: ";
    cin >> fileName;
    //opens file
    inputFile.open(fileName);
    //checks if file exists
    if (!inputFile) {
        cout << "Cannot open " << fileName << ". Check that file exists.\n";
        return 0;
    }
    //reads first line of the file
    getline (inputFile, header);
    //processes each number in the file
    while (inputFile >> n) {
        count++; //keeps count of how many numbers are in the file
        sum += n; //keeps a running sum
        if (n > max) { //keeps track of the max
            max = n;
        }
        if (n < min) { //keeps track of the min
            min = n;
        }
    }
    //closes file
    inputFile.close();
    //checks if there are any numbers in the file
    if (count == 0) {
        cout << "File does not contain any numbers";
        return 0;
    }
    //calculates the average number
    avg = static_cast<double>(sum) / count;
    //displays results
    cout << setw(20) << left << "Smallest" << setw(10) << right << min << endl;
    cout << setw(20) << left << "Largest" << setw(10) << right << max << endl;
    cout << setw(20) << left << "Average" << setw(10) << right << avg << endl;

    return 0;
}