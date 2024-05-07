/*Author: Ethan Hernandez
*midtermC.cpp
*This program will allow the user to pick which computer they would like to buy from a shop, along with a quantity, then show the total price.
*/ 
#include <iostream>
#include <iomanip>

using namespace std;

int main() { 
    //Variables
    char choice, shippingChoice;
    string brandName;
    int memorySize, itemQuantity, n = 5;
    double itemPrice, salesTax, subTotal, total, shippingCost;
    //Prices can only have two decimal numbers(cents)
    cout << setprecision(2) << fixed;
    //Displays store options
    cout << "Welcome to the CIS22A PC store. Here is the price list: \n\n";
    cout << "Memory Size/Brand" << setw(8) << "HP" << setw(11) << "Dell" << setw(11) << "Lenovo" << endl;
    cout << setw(15) << "16 gigabytes" << setw(12) << "899.99" << setw(10) << "869.99" << setw(10) << "809.99" << endl;
    cout << setw(15) << "8 gigabytes" << setw(12) << "819.99" << setw(10) << "779.99" << setw(10) << "739.99" << endl;
    //Gets input from user for choice of brand
    cout << "Enter the brand name of the PC (D for Dell, H for HP, L for Lenovo, X to Exit): ";
    cin.get(choice);
    //Allows user to exit the program with X/x
    if (choice == 'X' || choice == 'x')
        return 0;
    else if (choice != 'D' && choice != 'H' && choice != 'L') {
        cout << "Invalid brand. please enter D, H, or L.";
        return 0;    
    }
    //Choice of memory size
    cout << "\nEnter the memory size of the PC (8 or 16 gigabytes): ";
    cin >> memorySize;
    if (memorySize != 8 && memorySize != 16) { //Input validation
        cout << "Invalid memory size. Choose 8 or 16.";
        return 0;
    }
    //Quantity choice
    cout << "\nEnter PC quantity to buy: ";
    cin >> itemQuantity;
    if (itemQuantity < 0) { //Input validation for num < 0
        cout << "Invalid item quantity. It cannot be negative.";
        return 0;
    }
    else if (itemQuantity > 10) { //Input validation for num > 10
        cout << "Invalid item quantity. It cannot exceed 10.";
        return 0;
    }
    //Switch function for the different pc choices
    switch (choice) { 
        case 'H': 
            brandName = "HP";
            itemPrice = memorySize == 8 ? 819.99 : 899.99;
            n += 2;
            break;
        case 'D':
            brandName = "Dell";
            itemPrice = memorySize == 8 ? 779.99 : 869.99;
            break;
        case 'L':
            brandName = "Lenovo";
            itemPrice = memorySize == 8 ? 739.99 : 809.99;
            n -= 2;
            break;
    }
    //Price Calculation
    subTotal = itemPrice * itemQuantity;
    salesTax = subTotal * 0.0975;
    
    n = itemQuantity == 10 ? n-=1 : n; //Accounts for differences in character amounts for different brand names and quantities
    //Displays price + tax
    cout << "The item price for (" << itemQuantity << " x " << brandName << ") is" << setw(n) << '$' << setw(10) << subTotal << endl;
    cout << "The sales tax is" << setw(21) << '$' << setw(10) << salesTax << endl;
    //Shipping choice
    cout << "\nEnter shipping method (S for Standard, E for Express): ";
    cin >> shippingChoice;
    if (shippingChoice != 'S' && shippingChoice != 'E') { //Input validation
        cout << "Invalid shipping method. Select S or E.";
        return 0;
    }
    //If/else for shipping cost
    shippingCost = shippingChoice == 'S' ? 10.00 : 20.00; 
    cout << "Shipping cost is" << setw(21) << '$' << setw(10) << shippingCost << endl;
    //Displays total price and thanks the customer
    total = subTotal + salesTax + shippingCost;
    cout << "\nYour total bill is" << setw(19) << '$' << setw(10) << total << endl;
    cout << "Thank you for your purchase.\n";
    
    return 0;
}



