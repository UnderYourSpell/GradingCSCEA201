#include <iostream>
using namespace std;

// Function to calculate the minimum number of coins
void calculateChange(int change, int &quarters, int &dimes, int &nickels, int &pennies) {
    quarters = change / 25;
    change = change % 25;

    dimes = change / 10;
    change = change % 10;

    nickels = change / 5;
    change = change % 5;

    pennies = change; // whatever is left are pennies
}

int main() {
    int change1, change2;
    int quarters, dimes, nickels, pennies;

    // First test case
    cout << "Enter the amount of change (1-99): ";
    cin >> change1;

    calculateChange(change1, quarters, dimes, nickels, pennies);

    cout << "For " << change1 << " cents, you need:\n";
    cout << "Quarters: " << quarters << "\n";
    cout << "Dimes: " << dimes << "\n";
    cout << "Nickels: " << nickels << "\n";
    cout << "Pennies: " << pennies << "\n\n";

    // Second test case
    cout << "Enter another amount of change (1-99): ";
    cin >> change2;

    calculateChange(change2, quarters, dimes, nickels, pennies);

    cout << "For " << change2 << " cents, you need:\n";
    cout << "Quarters: " << quarters << "\n";
    cout << "Dimes: " << dimes << "\n";
    cout << "Nickels: " << nickels << "\n";
    cout << "Pennies: " << pennies << "\n";

    return 0;
}
