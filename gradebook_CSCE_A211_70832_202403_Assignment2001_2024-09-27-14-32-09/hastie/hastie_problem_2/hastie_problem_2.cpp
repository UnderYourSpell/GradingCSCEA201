#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

// game function
void diceGame(int& wallet) {

    // initializing variables here
    int dieOne, dieTwo, dieThree;
    int wager, numPick;
    srand((unsigned)time(0));

    cout << "You now have $" << wallet << endl;
    // how much to wager
    cout << "How much would you like to wager?" << endl;
    cin >> wager;
    // input validation
    while ((wager <= 0)) {
        cout << endl
            << "You can't bet less than 0! thats negative money buddy!"
            << "\n How much would you like to wager?" << endl;
        cin >> wager;
    }
    while ((wallet - wager) < 0) {
        cout << endl
            << "You dont have the money for that wager buddy."
            << "\n How much would you like to wager?" << endl;
        cin >> wager;
    }

    // what number the player picked
    cout << "Input a number from 1-6" << endl;
    cin >> numPick;

    // checks if number is between 1 and 6
    while (numPick <= 0 || numPick > 6) {
        cout << endl
            << "These are 6 sided dice buddy. please choose a number from 1-6: ";
        cin >> numPick;
    }
    // the three dice rolls
    dieOne = (rand() % 6) + 1;
    cout << "Die 1 landed on " << dieOne << "\n";
    dieTwo = (rand() % 6) + 1;
    cout << "Die 2 landed on " << dieTwo << "\n";
    dieThree = (rand() % 6) + 1;
    cout << "Die 3 landed on " << dieThree << "\n";

    // comparing the dice to the number picked
    if (dieOne == numPick && dieTwo == numPick && dieThree == numPick) {
        wallet += wager * 3;
        cout << "You tripled your money!!! you now have " << wallet << endl;
    }
    else if ((dieOne == numPick && dieTwo == numPick) ||
        (dieThree == numPick && dieTwo == numPick) ||
        (dieThree == numPick && dieOne == numPick)) {
        wallet += wager * 2;
        cout << "You doubled your money!!! you now have " << wallet << endl;
    }
    else if (dieOne == numPick || dieTwo == numPick || dieThree == numPick) {
        cout << "You broke even!!! you still have " << wallet << endl;
    }
    else {
        wallet -= wager;
        cout << "Awe man! thats too bad! You can still win the next one!" << endl;
    }
}
// Main function
int main() {
    int wallet = 100;
    int gameAgain = 1;
    // starts here
    cout << "Welcome to Chuck-a-luck. Im not gonna explain the rules so goodluck "
        "and dont complain. Wow look at that you have $"
        << wallet
        << " in your wallet. Dont ask how i know that. Lets go gambling! \n";

    diceGame(wallet);
    // checks the amount of money in wallet to see if the player can even continue
    // playing
    while (wallet > 0) {
        if (wallet == 0) {
            cout << "Aww boo you have no more money, you should have quit while you "
                "were ahead :(\n"
                << "YOU LOST!!! LOSER!!!! TAKE THE L AND LEAVE!!!" << endl;
            exit(0);
        }

        // asks whther or not the player wants to keep playing
        cout
            << "90 percent of gamblers quit before they win big, would you like to "
            "try again?"
            << endl
            << "0 for no, 1 for yes" << endl;
        cin >> gameAgain;

        while (gameAgain < 0 || gameAgain > 1) {
            cout << "Nuh uh!! that an invalid input! 0 for no, 1 for yes" << endl;
            cin >> gameAgain;
        }
        if (gameAgain == 0) {
            cout << "AWW MAN! You were about to win big! i can feel it! Come back!!!";
            exit(0);
        }
        else {
            diceGame(wallet);
        }
    }
    return 0;
}