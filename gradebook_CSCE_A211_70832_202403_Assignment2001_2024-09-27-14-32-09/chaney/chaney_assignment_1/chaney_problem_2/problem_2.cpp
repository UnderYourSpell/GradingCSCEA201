#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

// Function prototypes
int rollDice(int chosenNumber);
int getValidWager(int money);
int getValidNumber();

// Function to simulate rolling the dice and returning how many match the player's number
int rollDice(int chosenNumber) {
    int matches = 0;

    // Roll three six-sided dice
    for (int i = 0; i < 3; i++) {
        int diceRoll = rand() % 6 + 1;  // Generate a random number between 1 and 6
        cout << "Dice " << i+1 << " rolled: " << diceRoll << endl;
        if (diceRoll == chosenNumber) {
            matches++;
        }
    }

    return matches;
}

// Function to get a valid wager from the player
int getValidWager(int money) {
    int wager;
    do {
        cout << "You have $" << money << ". Enter your wager: ";
        cin >> wager;

        // Ensure wager is positive and doesn't exceed available money
        if (wager <= 0 || wager > money) {
            cout << "Invalid wager. Please enter a valid amount between 1 and $" << money << "." << endl;
        }
    } while (wager <= 0 || wager > money);

    return wager;
}

// Function to get a valid number from the player (between 1 and 6)
int getValidNumber() {
    int chosenNumber;
    do {
        cout << "Pick a number between 1 and 6: ";
        cin >> chosenNumber;

        // Ensure the chosen number is within the valid range
        if (chosenNumber < 1 || chosenNumber > 6) {
            cout << "Invalid number. Please choose a number between 1 and 6." << endl;
        }
    } while (chosenNumber < 1 || chosenNumber > 6);

    return chosenNumber;
}

int main() {
    srand(time(0));  // Seed for random number generation

    int money = 100;  // Initial amount of money for the player
    char playAgain;

    cout << "Welcome to Chuck-a-Luck! You start with $100." << endl;

    // Main game loop
    do {
        int wager = getValidWager(money);           // Get a valid wager from the player
        int chosenNumber = getValidNumber();        // Get a valid number from the player

        // Roll the dice and check how many times the chosen number appears
        int matches = rollDice(chosenNumber);

        // Determine outcome based on how many dice match the chosen number
        if (matches == 0) {
            cout << "None of the dice matched your number. You lost $" << wager << "." << endl;
            money -= wager;  // Deduct the wager from the player's money
        } else if (matches == 1) {
            cout << "One die matched your number. You break even and keep your wager." << endl;
        } else if (matches == 2) {
            cout << "Two dice matched your number. You win $" << wager * 2 << "!" << endl;
            money += wager * 2;  // Add twice the wager to the player's money
        } else {
            cout << "All three dice matched your number! You win $" << wager * 3 << "!" << endl;
            money += wager * 3;  // Add three times the wager to the player's money
        }

        // Check if the player has run out of money
        if (money <= 0) {
            cout << "You're out of money! Game over." << endl;
            break;  // End the game if the player has no money left
        }

        // Ask the player if they want to play again
        cout << "You now have $" << money << ". Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');  // Repeat the game loop if the player wants to play again

    cout << "Thanks for playing! You leave with $" << money << "." << endl;

    return 0;
}
