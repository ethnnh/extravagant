#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Variables
    char order;
    string itemName;
    int itemQuantity, itemMaxQuantity;
    double itemPrice, totalPrice, totalBill, tip, salesTax;

    cout << setprecision(2) << fixed;

    cout << "Welcome to the CIS22A restaurant. You can choose of the following items : \n";
    cout << setw(25) << left << "A- Sea Bass, price" << setw(10) << right << "$35.99" << endl;
    cout << setw(25) << left << "B- Angus Steak, price" << setw(10) << right << "$28.99" << endl;
    cout << setw(25) << left << "C- Lemon Chicken, price" << setw(10) << right << "$18.99" << endl;
    cout << setw(25) << left << "D- Beef Burger, price" << setw(10) << right << "$11.99" << endl;
    cout << setw(25) << left << "E- Ceasar Salad, price" << setw(10) << right << "$8.99" << endl;
    cout << setw(25) << left << "F- Clam Chowder, price" << setw(10) << right << "$7.99" << endl;
    cout << setw(25) << left << "G- Soft drink, price" << setw(10) << right << "$2.79" << endl;
    cout << setw(25) << left << "H- Tea, price" << setw(10) << right << "$2.19" << endl;
    cout << setw(25) << left << "I- Apple Juice, price" << setw(10) << right << "$2.50" << endl;

    cout << "\nSelect a letter from the menu: ";
    cin >> order;
    cout << "\nEnter the quantity: ";
    cin >> itemQuantity;

    if (order < 'I')
    {
        switch (order)
        {
        case 'A':
            itemName = "Sea Bass";
            itemPrice = 35.99;
            itemMaxQuantity = 50;
            break;
        case 'B':
            itemName = "Angus Steak";
            itemPrice = 28.99;
            itemMaxQuantity = 50;
            break;
        case 'C':
            itemName = "Lemon Chicken";
            itemPrice = 18.99;
            itemMaxQuantity = 50;
            break;
        case 'D':
            itemName = "Beef Burger";
            itemPrice = 11.99;
            itemMaxQuantity = 200;
            break;
        case 'E':
            itemName = "Ceasar Salad";
            itemPrice = 8.99;
            itemMaxQuantity = 200;
            break;
        case 'F':
            itemName = "Clam Chowder";
            itemPrice = 7.99;
            itemMaxQuantity = 200;
            break;
        case 'G':
            itemName = "Soft Drink";
            itemPrice = 2.79;
            itemMaxQuantity = 200;
            break;
        case 'H':
            itemName = "Tea";
            itemPrice = 2.19;
            itemMaxQuantity = 200;
            break;
        case 'I':
            itemName = "Apple Juice";
            itemPrice = 2.50;
            itemMaxQuantity = 200;
            break;
        }

        if (itemQuantity > itemMaxQuantity)
            cout << "Invalid item quantity. It must not exceed " << itemMaxQuantity << ".\n";
        else if (itemQuantity)
            cout << "Invalid item quantity. It cannot be negative.\n";
        else
        {
            totalPrice = itemPrice * itemQuantity;
            salesTax = totalPrice * 0.0975;

            cout << "The total price for (" << itemQuantity << " x " << itemName << ") is: $" << totalPrice << endl;
            cout << "The sale tax is $" << salesTax << endl;

            cout << "Enter the gratuity amount: ";
            cin >> tip;

            if (tip < 0)
                cout << "Invalid gratuity amount.";
            else
            {
                totalBill = totalPrice + salesTax + tip;
                cout << "Your final total bill is: $" << totalBill << endl;
 