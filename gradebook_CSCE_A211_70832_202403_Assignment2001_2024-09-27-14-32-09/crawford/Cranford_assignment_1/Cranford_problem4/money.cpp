#include <iostream>
using namespace std;

void calculate(int change, int& quarters, int& dimes, int& nickels, int& pennies) {
    quarters = change / 25;
    change %= 25;
    dimes = change / 10;
    change %= 10;
    nickels = change / 5;
    pennies = change % 5;
}

int main() {
    int change, quarters, dimes, nickels, pennies;

    cout << "Enter amount of change (1-99): ";
    cin >> change;
    calculate(change, quarters, dimes, nickels, pennies);
    cout << "Quarters: " << quarters << "\nDimes: " << dimes << "\nNickels: " << nickels << "\nPennies: " << pennies << endl;

    cout << "\nEnter amount of change (1-99): ";
    cin >> change;
    calculate(change, quarters, dimes, nickels, pennies);
    cout << "Quarters: " << quarters << "\nDimes: " << dimes << "\nNickels: " << nickels << "\nPennies: " << pennies << endl;

    return 0;
}

// Code will go outside of 1-99 the assignment word document didn't mention adding error checking so I assumed this is fine.
// Obviously for real world applications this isn't ideal due to Overflows and Possible code Injection but I assume we'll talk about this later?