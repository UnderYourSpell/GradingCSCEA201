// Critchfield_Problem 4.cpp : Write a program that reads an integer from 1-99 that represents some amount of change to dispense. 
//


#include <iostream>
using namespace std;

// calculating # of quarters, dimes, nickels, and pennies
void calculateChange(int amount, int& quarters, int& dimes, int& nickels, int& pennies) {
   
    quarters = amount / 25;
    amount = amount % 25; 

    
    dimes = amount / 10;
    amount = amount % 10; 

    
    nickels = amount / 5;
    amount = amount % 5; 

   
    pennies = amount;
}

int main() {
    int changeAmount;
    int quarters, dimes, nickels, pennies;

    // Case 1
    cout << "Enter an amount of change 1-99: ";
    cin >> changeAmount;

    if (changeAmount < 1 || changeAmount > 99) {
        cout << "Please enter a value between 1 and 99." << endl;
        return 1;
    }

    // Call the function to calculate the change
    calculateChange(changeAmount, quarters, dimes, nickels, pennies);

    // Output for Case 1
    cout << "For " << changeAmount << " cents, you need:" << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << pennies << " pennies." << endl;

    // Case 2
    cout << "\nEnter another amount of change (1-99): ";
    cin >> changeAmount;

    if (changeAmount < 1 || changeAmount > 99) {
        cout << "Please enter a value between 1 and 99." << endl;
        return 1;
    }

    // Call the function to calculate the change
    calculateChange(changeAmount, quarters, dimes, nickels, pennies);

    // Output for Case 2
    cout << "For " << changeAmount << " cents, you need:" << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << pennies << " pennies." << endl;

    return 0;
}
