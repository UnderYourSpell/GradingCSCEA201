#include <iostream>
using namespace std;

void calculateCoins(int change, int& quarters, int& dimes, int& nickels, int& pennies) {
    quarters = change / 25;
    change %= 25;
    dimes = change / 10;
    change %= 10;
    nickels = change / 5;
    pennies = change % 5;
}

int main() {
    int change;
    cout << "Enter an amount of change (1-99 cents): ";
    cin >> change;

    int quarters, dimes, nickels, pennies;

    calculateCoins(change, quarters, dimes, nickels, pennies);

    cout << "You need:" << endl;
    cout << quarters << " quarters" << endl;
    cout << dimes << " dimes" << endl;
    cout << nickels << " nickels" << endl;
    cout << pennies << " pennies" << endl;

    return 0;
}
