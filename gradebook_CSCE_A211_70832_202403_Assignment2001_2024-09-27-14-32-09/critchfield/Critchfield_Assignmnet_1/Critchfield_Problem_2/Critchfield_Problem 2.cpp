// Critchfield_Problem 2.cpp : Write a program that implements a C++ version of Chuck-a-luck.
//

#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
   
    srand(time(0));

    // starting money
    int money = 100;
    int wager;
    int chosenNumber;
    char playAgain;

    cout << "You start with $100." << endl;

    // Main game loop
    do {
        // Ask and checking for wager
        do {
            cout << "You have $" << money << ". Enter your wager: ";
            cin >> wager;

            if (wager > money) {
                cout << "You can't wager more than you have " << endl;
            }
        } while (wager > money);  // Repeat if wager is invalid

        // pick a number between 1 - 6
        do {
            cout << "Pick a number between 1 and 6: ";
            cin >> chosenNumber;

            if (chosenNumber < 1 || chosenNumber > 6) {
                cout << "That's not a valid number. choose a number between 1 and 6." << endl;
            }
        } while (chosenNumber < 1 || chosenNumber > 6);  

        // Roll 3 dice
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        int dice3 = rand() % 6 + 1;

        // Show dice results
        cout << "The dice rolled: " << dice1 << " " << dice2 << " " << dice3 << endl;

  
        int matchCount = 0;
        if (dice1 == chosenNumber) matchCount++;
        if (dice2 == chosenNumber) matchCount++;
        if (dice3 == chosenNumber) matchCount++;

        // Calculate the result based on matches
        if (matchCount == 0) {
            cout << "You lost $" << wager << "." << endl;
            money -= wager;  // Subtract wager from money
        }
        else if (matchCount == 1) {
            cout << "You win your wager of $" << wager  << endl;
            // No change in money 
        }
        else if (matchCount == 2) {
            cout << "Two matches! You win $" << wager << endl;
            money += wager;  // Add the wager as winnings total 2x wager
        }
        else if (matchCount == 3) {
            cout << "Three matches! You win $" << wager * 2 <<  endl;
            money += wager * 2;  // Add two times the wager as winnings total 3x wager
        }

        // Check if player still has money
        if (money <= 0) {
            cout << "You're out of money!" << endl;
            break;  
        }

        // Ask if the player wants to play again
        cout << "You now have $" << money << ". Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');  

    cout << "Thanks for playing! You leave with $" << money << "." << endl;

    return 0;
}
