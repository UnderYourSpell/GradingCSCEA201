#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRoll();

int rollandMatch(int g);

int main() {

	srand(time(NULL));
	int money = 100;
	int w;
	int n;
	char q = 'y';


	while (q != 'n') {
		cout << "You have $" << money << ", would you like to place a bet and pick a number? (y/n)" << endl;
		cin >> q;
		q = tolower(q);
		if (q == 'n') {
			break;
		}
		else if (q == 'y') {
			cout << "Aright place your wager." << endl;

			while (true) {
				cin >> w;
				if (w > money) {
					cout << "Sorry, pal. You don't have enough money for that bet, try again." << endl;
				}
				else if (w <= 0) {
					cout << "Sorry, pal. You have to pay to play, try again." << endl;
				}
				else {
					break;
				}
			}

			cout << "Aright choose you lucky number, 1-6." << endl;

			while (true) {
				cin >> n;
				if (n > 6) {
					cout << "Sorry, pal. We only have six sided dice on hand, try again." << endl;
				}
				else if (w <= 0) {
					cout << "Sorry, pal. I haven't even heard of dice that can roll that number, try again." << endl;
				}
				else {
					break;
				}
			}


			while (true) {
				cout << "Take a moment and wish for some good luck. When ready press y to roll the dice... or enter n to back out..." << endl;
				char input;
				cin >> input;

				if (input == 'n') {
					cout << "Oh, you don't want to roll! Smart guy, you were probably gonna lose anyway, here's your cash back." << endl;
					break;
				}
				else if (input == 'y') {

					int matches = rollandMatch(n);

					switch (matches) {
					case 0:
						cout << "Sorry pal, you guessed wrong. You lost your wager." << endl;
						money -= w;
						break;
					case 1:
						cout << "Nice! You got 1 match! You win back your wager!" << endl;
						break;
					case 2:
						cout << "Congrats, you got 2 matches! You win double your wager!" << endl;
						money += w * 2;
						break;
					case 3:
						cout << "Woah, what luck! You got 3 matches! You win triple your wager!" << endl;
						money += w * 3;
						break;
					}
					break;
				}
				else {
					cout << "Sorry pal, I couldn't hear what you said. Could you repeat that?" << endl;
				}
			}
		}
		else {
			cout << "Sorry pal, I couldn't hear what you said. Could you repeat that?" << endl;
		}

		if (money <= 0) {
			cout << "You have run out of money. Game over!" << endl;
			break;
		}

	}

	cout << "Thanks for playing! You left with $" << money << " to your name." << endl;
	return 0;

}

int getRoll() {
	return rand() % 6 + 1;
}

int rollandMatch(int g) {
	int dice1 = getRoll();
	int dice2 = getRoll();
	int dice3 = getRoll();

	cout << "Okay, first dice roll is a.. " << dice1 << "! Second roll is a.. " << dice2 << "! And the final roll is a.. " << dice3 << endl;

	int matched = 0;
	if (dice1 == g) matched++;
	if (dice2 == g) matched++;
	if (dice3 == g) matched++;

	return matched;
}