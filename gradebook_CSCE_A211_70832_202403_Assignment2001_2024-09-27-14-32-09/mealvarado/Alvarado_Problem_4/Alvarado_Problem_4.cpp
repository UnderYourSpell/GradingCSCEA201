#include <iostream>
using namespace std;

void calculateChange(int money, int &quarters, int &dimes, int &nickles, int &pennies) {
    quarters = money / 25;
    money %= 25;

    dimes = money / 10;
    money %= 10;

    nickles = money / 5;
    money %= 5;

    pennies = money / 1;
    money %= 1;
}

int main() {
    int money1 = 67;
    int quarters, dimes, nickles, pennies;

    calculateChange(money1, quarters, dimes, nickles, pennies);

    cout << "Quarters needed: " << quarters << endl;
    cout << "Dimes needed: " << dimes << endl;
    cout << "Nickles needed: " << nickles << endl;
    cout << "Pennies needed: " << pennies << endl;

    cout << "\n";

    int money2 = 72;

    calculateChange(money2, quarters, dimes, nickles, pennies);

    cout << "Quarters needed: " << quarters << endl;
    cout << "Dimes needed: " << dimes << endl;
    cout << "Nickles needed: " << nickles << endl;
    cout << "Pennies needed: " << pennies << endl;

    return 0;
}