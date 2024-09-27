// A1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;

void rollTheDice(int&, int, int);
void doWager(int&);

int main()
{
    srand(time(0));

    int cash = 100;
    int yn;


    while (cash > 0) {
        
        do
        {
            cout << "Would you like to continue playing?(1 for yes 2 for no): ";
            cin >> yn;
        } while (yn != 1 && yn != 2);

        if (yn == 2) {
            cout << "You left with " << cash << " Dollars." << endl << "Thank you for playing." << endl;
            break;
        }
        else {
            doWager(cash);
            cout << "You currently have: " << cash << " dollars." << endl;
        }
    }
}

void doWager(int& cash) {
    int wager, gamblerNum;
    
    do
    {
        cout << "How much would you like to wager(1 - " << cash << "): ";
        cin >> wager;
    } while (wager > cash);

    do
    {
        cout << "Enter your number (1-6): ";
        cin >> gamblerNum;
    } while (gamblerNum > 6 || gamblerNum < 1);

    rollTheDice(cash, wager, gamblerNum);
}

void rollTheDice(int& cash, int wager, int gamblerNum) {
    int dice[3];
    int numRight = 0;

    for (int i = 0; i < 3; i++) {
        dice[i] = (rand() % 6) + 1;
        if (dice[i] == gamblerNum) {
            numRight += 1;
        }
        cout << "Roll " << i + 1 << " was a " << dice[i] << "." << endl;
    }

    if (numRight == 0) {
        cout << "None were " << gamblerNum << "s. You lost: " << wager << " dollars." << endl;
        cash -= wager;
    }
    else if (numRight == 1) {
        cout << "You rolled 1 " << gamblerNum << ". You broke even." << endl;
    }
    else if (numRight == 2) {
        cout << "You rolled 2 " << gamblerNum << "s. You made: " << wager << " dollars." << endl;
        cash += wager;
    }
    else if (numRight == 3) {
        cout << "You rolled 3 " << gamblerNum << "s. You made: " << 2 * wager << " dollars." << endl;
        cash += (2 * wager);
    }
}