#include <iostream>
using namespace std;

void calculateChange(int amount, int& quarters, int& dimes, int& nickels, int& pennies);
void outputChange(int amount, int quarters, int dimes, int nickels, int pennies);


int main() {
    int amount;
    int quarters;
    int dimes;
    int nickels;
    int pennies;


    amount = 87;
    calculateChange(amount, quarters, dimes, nickels, pennies);
    outputChange(amount, quarters, dimes, nickels, pennies);

    cout << endl;

    amount = 49;
    calculateChange(amount, quarters, dimes, nickels, pennies);
    outputChange(amount, quarters, dimes, nickels, pennies);

    return 0;
}


void calculateChange(int amount, int& quarters, int& dimes, int& nickels, int& pennies) {
    quarters = amount / 25;
    amount %= 25;

    dimes = amount / 10;
    amount %= 10;

    nickels = amount / 5;
    amount %= 5;

    pennies = amount;
}

void outputChange(int amount, int quarters, int dimes, int nickels, int pennies) {
    cout << amount << " cents has " << endl;
    cout << quarters << " Quarters." << endl;
    cout << dimes << " Dimes" << endl;
    cout << nickels << " Nickels" << endl;
    cout << pennies << " Pennies" << endl;
}
