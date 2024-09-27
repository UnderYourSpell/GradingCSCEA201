// Question 3
// Jayson Cristobal
// 09.16.2024

#include <iostream>
using namespace std;

void calcChange (int change, int &quarters, int &dimes, int &nickels, int &pennies)
{
    quarters = change / 25;
    change %= 25;

    dimes = change / 10;
    change %= 10;

    nickels = change / 5;
    change %= 5;

    pennies = change;
}

int main()
{
    int change;
    int quar, dimes, nickels, pennies;

    //test code 1
    change = 72;

    calcChange (change, quar, dimes, nickels, pennies);
    cout << "With " << change << " in change, you can get: " << endl;
    cout << "Quarters: " << quar << endl;
    cout << "Dimees: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;

    //test code 2
    change = 245;

    calcChange (change, quar, dimes, nickels, pennies);
    cout << "With " << change << " in change, you can get: " << endl;
    cout << "Quarters: " << quar << endl;
    cout << "Dimees: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;

    //user input
    cout << "Enter your change: ";
    cin >> change;

    calcChange (change, quar, dimes, nickels, pennies);
    cout << "With " << change << " in change, you can get: " << endl;
    cout << "Quarters: " << quar << endl;
    cout << "Dimees: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;

    return 0;
}