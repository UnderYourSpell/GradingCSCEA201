#include <iostream>
using namespace std;

void coinCounter(float, int&, int&, int&, int&);

int main()
{
	int quarters, dimes, nickels, pennies;
	float money, test1 = 56.9, test2 = 98.37;

	cout << "Enter amount of money (1-99): ";
	cin >> money;

	coinCounter(money, quarters, dimes, nickels, pennies);
	cout << "Quarters: " << quarters << endl << "Dimes: " << dimes << endl << "Nickels: " << nickels << endl << "Pennies: " << pennies << endl;

	coinCounter(test1, quarters, dimes, nickels, pennies);
	cout << endl << endl << "TEST 1" << endl << endl << "Quarters: " << quarters << endl << "Dimes: " << dimes << endl << "Nickels: " << nickels << endl << "Pennies: " << pennies << endl;

	coinCounter(test2, quarters, dimes, nickels, pennies);
	cout << endl << endl << "TEST 2" << endl << endl << "Quarters: " << quarters << endl << "Dimes: " << dimes << endl << "Nickels: " << nickels << endl << "Pennies: " << pennies << endl;

	return 0;
}

void coinCounter(float money, int& quarters, int& dimes, int& nickels, int& pennies) {
	int cents = money * 100;
	quarters = cents / 25;
	cents = cents % 25;
	dimes = cents / 10;
	cents = cents % 10;
	nickels = cents / 5;
	cents = cents % 5;
	pennies = cents;
}