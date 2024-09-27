

#include <iostream>

using namespace std;

void dispenseCoins(int change, int& quarters, int& dimes, int& nickels, int& pennies);

int main()
{
    int change;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    // Test
    change = 99;
    dispenseCoins(change, quarters, dimes, nickels, pennies);
    cout << "Change value: $0." << change << endl;
    cout << "You recieved: " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies.\n";

    change = 66;
    dispenseCoins(change, quarters, dimes, nickels, pennies);
    cout << "Change value: $0." << change << endl;
    cout << "You recieved: " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies.\n";

}

void dispenseCoins(int change, int& quarters, int& dimes, int& nickels, int& pennies)
{
    quarters = change / 25;
    change %= 25;

    dimes = change / 10;
    change %= 10;

    nickels = change / 5;
    change %= 5;

    pennies = change;
}

