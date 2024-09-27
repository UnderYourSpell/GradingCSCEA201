#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;


void playRound(int &total) {
    int wager, guess, roll, mult = 0;

    cout << "How much are you betting?\nYou have $" << total << " left to wager: ";
    cin >> wager;
    while (wager > total) {
        cout << "Woah there, you don't have the money to wager that high. Try again. (You have $" << total << " left to spend): ";
        cin >> wager;
    }
    total -= wager;

    cout << "What number are you choosing (1-6): ";
    cin >> guess;
    while (guess < 1 || guess > 6) {
        cout << "Woah there, you need to pick a number between 1-6. No other numbers appear on a six-sided die. Try again: ";
        cin >> guess;
    }

    cout << "Press enter to roll the dice"; //Was added to satisfy the intiate rolling dice  section
    cin.ignore();  
    cin.get();   

    // Roll the dice three times
    for (int i = 0; i < 3; ++i) {
        roll = rand() % 6 + 1;
        cout << "The die was a " << roll << endl;
        if (guess == roll) {
            mult++;
        }
    }


    if (mult == 0) {
        cout << "Tough luck partner, you did not win a single time.\n";
    } else {
        int winnings = mult * wager;
        cout << "You won $" << winnings << endl;
        total += winnings; 
    }
}

int main() {
    srand(time(0));  
    int total = 100;

    while (total > 0) {
        playRound(total);
    }

    cout << "Game over. You have $" << total << " left.\n";
    
    return 0;
}
