#include <iostream>

using namespace std;

void getChange(int, int&, int&, int&, int&);

void testGetChange(int);

int main()
{
	int testAmount;

	testGetChange(45);
	testGetChange(99);
	testGetChange(24);

	return 0;
}

// THIS IS THE FUNCTION ANSWERING THE QUESTION
void getChange(int amount, int& quarters, int& dimes, int& nickels, int& pennies)
{
	if (amount < 1 || amount > 99) return;

	quarters = amount / 25;
	amount -= quarters * 25;

	dimes = amount / 10;
	amount -= dimes * 10;

	nickels = amount / 5;
	amount -= nickels * 5;

	pennies = amount;
}

// THIS IS MY TEST FUNCTION
void testGetChange(int amount)
{
	int quarters;
	int dimes;
	int nickels;
	int pennies;

	getChange(amount, quarters, dimes, nickels, pennies);

	cout << "\nOriginal Amount: " << amount << endl;
	cout << "\tQuarters: " << quarters << endl;
	cout << "\tDimes: " << dimes << endl;
	cout << "\tNickels: " << nickels << endl;
	cout << "\tPennies: " << pennies << endl;

	// If the starting amount and end amount are the same then everything should be working properly

	int endAmount = (quarters * 25) + (dimes * 10) + (nickels * 5) + pennies;

	if (endAmount == amount)
		cout << "Test Passed!" << endl;
	else
		cout << "Test Failed..." << endl;
}
