#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
using namespace std;

void rollDice(int& dice1, int& dice2, int& dice3) {
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    dice3 = rand() % 6 + 1;
}

int main() {
    srand(time(0));  // random number generator

    int money = 100;  // Initial money
    int wager, chosenNumber;
    char playAgain;

    do {
        cout << "You have $" << money << ". Enter your wager: ";
        cin >> wager;

        // Make sure the wager is valid
        while (wager > money || wager <= 0) {
            cout << "Invalid wager. Enter a valid wager: ";
            cin >> wager;
        }

        cout << "Choose a number between 1 and 6: ";
        cin >> chosenNumber;

        // Make sure the chosen number is valid
        while (chosenNumber < 1 || chosenNumber > 6) {
            cout << "Invalid number. Choose a number between 1 and 6: ";
            cin >> chosenNumber;
        }

        int dice1, dice2, dice3;
        rollDice(dice1, dice2, dice3);

        cout << "The dice rolled: " << dice1 << ", " << dice2 << ", " << dice3 << endl;

        int matchCount = (dice1 == chosenNumber) + (dice2 == chosenNumber) + (dice3 == chosenNumber);

        if (matchCount == 0) {
            cout << "You lose $" << wager << "!" << endl;
            money -= wager;
        }
        else if (matchCount == 1) {
            cout << "You win $" << wager << "!" << endl;
            money += wager;
        }
        else if (matchCount == 2) {
            cout << "You win $" << wager * 2 << "!" << endl;
            money += wager * 2;
        }
        else if (matchCount == 3) {
            cout << "You win $" << wager * 3 << "!" << endl;
            money += wager * 3;
        }

        // Check if the player still has money
        if (money <= 0) {
            cout << "You're out of money!" << endl;
            break;
        }

        // Ask if the player wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! You finished with $" << money << "." << endl;

    return 0;
}
