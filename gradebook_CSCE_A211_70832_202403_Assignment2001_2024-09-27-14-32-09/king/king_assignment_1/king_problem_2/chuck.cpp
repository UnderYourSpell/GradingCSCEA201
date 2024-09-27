#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function to prompt user to select number and validate input
int pickNum() {
	int bet;
	cout << endl << "Choose a number between 1-6: ";
	cin >> bet;

	while (true) {
		if (cin.fail()){
			cout << "Error! Please enter an integer: ";
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> bet;
		} else if (bet < 1 || bet > 6) {
			cout << "Please enter a number between 1-6: ";
			cin >> bet;
		} else {
			break;
		}
	}
	return bet;
}

// Function to simulate dice roll and calculate result
int rollResult(int bet) {
	int result = 0;

	int d[3] = {1 + rand() % 6, 1 + rand() % 6, 1 + rand() % 6};

	for (int i = 0; i < 3; i++) {
		cout << "You rolled a " << d[i] << "!" << endl;
		if (i == 0)
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
	for (int i : d) {
		if (bet == i) ++result;
	}
	return result;
}

// Function to check for single character input
char get_char() {
	char ch;
	cin.get(ch);

	while (cin.get() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a valid option: ";
		cin.get(ch);
	}

	return ch;
}

// Function to get wager and validate input
int wager(int cash) {
	
	int cash_wager;

	cout << endl << "Enter wager: ";
	cin >> cash_wager;

	while (true) {
		if (cin.fail()){
			cout << "Error! Please enter an integer: ";
		} else if (cash_wager > cash) {
			cout << "You cannot bet more than you have. Please enter a valid wager. You have $" << cash << ": ";
		} else if (cash_wager < 1) {
			cout << "You must bet at least $1. Please enter a valid wager: ";
		} else {
			break;
		} 
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> cash_wager;
	}

	return cash_wager;
}

// Function to output winnings and current cash
void winnings(int &cash, int result, int wager) {
	if (result == 0) {
		cout << endl << "You lost the wager." << endl;
		cash -= wager;
		cout << "You now have $" << cash << endl;
	} else {
		cout << endl << "Congrats! You won! You have earned " << result << "x your wager." << endl;
		cash += (result * wager);
		cout << "You now have $" << cash << endl;
	}
}

int main() {
	
	// Initialize game state
	int cash = 100;
	bool play = 1;
	srand(time(NULL));

	cout << "Welcome to Chuck-A-Luck!" << endl;

	while ( cash > 0 && play ) {
		cout << endl << "You have $" << cash << " to wager." << endl;
		
		// Get player wager
		int cash_wager = wager(cash);		

		// Get player's dice bet
		int bet = pickNum();

		// Roll dice and hold result
		int result = rollResult(bet);
		
		// Output winnings and current cash
		winnings(cash, result, cash_wager);
	
		if (cash > 0) {
			cout << "Press any key to play again or ! to quit: ";
			char choice = getchar();
			if (choice == '!') {
				play = 0;
			}
		}	else {
			cout << "You have nothing left to bet." << endl;
		}
	}

	cout << "Thanks for playing! Your winnings are $" << cash << endl;
	return 0;
}
