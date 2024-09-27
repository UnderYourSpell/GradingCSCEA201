#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

// void function to make change
void changeMaker(int userNum, int& quarters, int& dimes, int& nickels,
    int& pennies) {

    cout << "For $" << userNum << " you get: " << endl;
    // calculation block
    quarters = userNum / 25;
    userNum = userNum % 25;

    dimes = userNum / 10;
    userNum = userNum % 10;

    nickels = userNum / 5;
    userNum = userNum % 5;

    pennies = userNum;
    //output block
    cout << quarters << " quarters in change." << endl;
    cout << dimes << " dimes in change." << endl;
    cout << nickels << " nickels in change." << endl;
    cout << pennies << " pennies in change." << endl << endl;
}
int main() {
    int userNum, quarters, dimes, nickels, pennies; // initialize variables
    // user gets to input
    cout << "Please input a number from 1-99: ";
    cin >> userNum;
    while (userNum <= 0 || userNum > 99) {
        cout << endl << "Invalid input, please input a number from 1-99: ";
    }

    changeMaker(userNum, quarters, dimes, nickels, pennies);

    userNum = 67;
    changeMaker(userNum, quarters, dimes, nickels, pennies);

    userNum = 32;
    changeMaker(userNum, quarters, dimes, nickels, pennies);
}