#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function that rolls three dice and then stores into an array
void rollDice(int dice[]) {
    for (int i = 0; i < 3; ++i) {
        dice[i] = rand() % 6 + 1;
    }
}


int main() {
    srand(time(0)); 

    int money = 100;
    int wager, n;
    char playAgain;

    cout << "Welcome to Chuck-a-Luck! You start with $100." << endl;

    do {
        do {
            cout << "You have " << money << ". Enter your wager: ";
            cin >> wager;
        } while (wager > money);

        do {
            cout << "Pick a number between 1-6: ";
            cin >> n;
        } while (1 > n || 6 < n);

        int dice[3];
        rollDice(dice);

        cout << "The dice rolled: " << dice[0] << " " << dice[1] << " " << dice[2] << endl;

        // Calculates the result
        int matches = 0;
        for (int i = 0; i < 3; ++i) {
            if (dice[i] == n) {
                ++matches;
            }
        }

        // Outputs the game and wager results
        if (matches == 0) {
            cout << "You lost $" << wager << "." << endl;
            money -= wager;
        } else if (matches == 1) {
            cout << "You won even money! You win $" << wager << "." << endl;
        } else if (matches == 2) {
            cout << "You won 2-to-1! You win $" << wager * 2 << "." << endl;
            money += wager;
        } else if (matches == 3) {
            cout << "You won 3-to-1! You win $" << wager * 3 << "." << endl;
            money += wager * 2;
        }

        if (money <= 0) {
            cout << "You're out of money! Game over." << endl;
            break;
        }

        cout << "You now have $" << money << ". Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! You ended with $" << money << "." << endl;

    return 0;
}