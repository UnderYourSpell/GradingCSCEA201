#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void calcChange(int change, int &quarters, int &dimes, int &nickels, int &pennies) {
	quarters = change / 25;
	change %= 25;
	dimes = change / 10;
	change %= 10;
	nickels = change / 5;
	change %= 5;
	pennies = change;
}

int main() {
	
	int change, quarters, dimes, nickels, pennies;

	cout << "Enter change amount from 1-99: ";
	cin >> change;
	
	while (true) {
		if (cin.fail()) {
			cout << "Please enter a integer: ";
		} else if (change < 1 || change > 99) {
			cout << "Please enter an integer from 1-99: ";
		}
		else {
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> change;
	}
	
	calcChange(change, quarters, dimes, nickels, pennies);

	cout << "For " << change << " cent(s) in change, you need:" << endl;
	cout << "Quarters: " << quarters << endl;
	cout << "Dimes: " << dimes << endl;
	cout << "Nickels: " << nickels << endl;
	cout << "Pennies: " << pennies << endl;

	return 0;
}
