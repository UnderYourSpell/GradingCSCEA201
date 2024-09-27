//Run a version of a casino game called "Chuck-A-Luck"

#include <iostream>
#include <ctime>
#include <random>

using namespace std;

//Declare functions
void chuck(int& x);

int main()
{
    int MONEY = 100;
    bool is_playing = true;
    
    cout << "Welcome to the Casino!\n";

    //Keeps the player in a loop until they decide to stop playing
    while (is_playing)
    {
        char choice = ' ';

        cout << "Your current funds: $" << MONEY << endl;

        if (MONEY <= 0)
        {
            cout << "Sorry! You're outta money! You're gonna have to leave." << endl << endl;
            is_playing = false;
            break;
        }

        while (choice != 'y' && choice != 'n')
        {
            cout << "\nWould you like to play a round of Chuck-A-Luck? (y/n) : ";
            cin >> choice;

            if (choice == 'y')
                chuck(MONEY);
            else if (choice == 'n')
                is_playing = false;
            else
                cout << "Invalid input, please select y or n." << endl << endl;

        }
    }

    //Show the player their final earnings
    cout << "\nYour total earnings: $" << MONEY - 100 << endl;
    cout << "\nGoodbye!";
    
    return 0;
}

//The function that plays chuck-a-luck, the only function input is the user's current money value
void chuck(int& x)
{
    bool good_wager = false;
    bool valid_n = false;
    
    int wager = 0;
    int rollA, rollB, rollC;
    int n;

    //Prompt the user to put in a valid wager
    while (!good_wager) 
    {
        cout << "\nHow much would you like to wager?" << endl << "$";
        cin >> wager;

        if (wager <= 0)
            cout << "Sorry! You need to put SOMETHING on the table!" << endl << endl;
        else if (wager > x)
            cout << "It appears you don't have enough money for that kind of bet!" << endl << endl;
        else
            good_wager = true;
    }
    
    //Prompt the user to put in a valid side of a six-sided die
    while (!valid_n)
    {
        cout << "\nWhich side of the dice is feeling lucky to you? (1-6) : ";
        cin >> n;

        if (n < 1 || n > 6)
            cout << "Sorry pal, you need to pick a value on a SIX sided die!" << endl << endl;
        else
        {
            cout << "\nSo you chose " << n << ", huh? Aighty" << endl << endl;
            valid_n = true;
        }
    }

    cout << "Press enter to roll the die" << endl;
    cin.ignore();
    cin.get();
    
    //Seed the random number generator
    srand(time(NULL));

    //Roll Dice
    rollA = rand() % 6 + 1;
    rollB = rand() % 6 + 1;
    rollC = rand() % 6 + 1;
    
    cout << "Roll 1: " << rollA << endl;
    cout << "Roll 2: " << rollB << endl;
    cout << "Roll 3: " << rollC << endl;
    
    //Determine whether a user won or lost
    if (rollA == n || rollB == n || rollC == n)
    {
        cout << "\nCongratulations, you won!" << endl << endl;

        //Add money to the user's bank depending on how many rolls are the same
        if (rollA == n)
            x += wager;
        if (rollB == n)
            x += wager;
        if (rollC == n)
            x += wager;
    }
    else
    {
        cout << "Sorry! Better luck next time!" << endl << endl;
        x -= wager;
    } 

    return;
}
