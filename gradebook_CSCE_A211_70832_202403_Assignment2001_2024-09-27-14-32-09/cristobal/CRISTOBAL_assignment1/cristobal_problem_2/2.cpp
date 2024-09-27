// Question 2
// Jayson Cristobal
// 09.15.2024

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int dice_roll()
{
    return rand() % 6 + 1;
}

int main()
{
    int cash = 100;
    int wager, roll_num, roll1, roll2, roll3;
    char choice;

    cout << "Welcome to Chuck-a-luck!" << endl;

    while (cash > 0)
    {
        cout << "You currently have $" << cash << "\nPlease enter your wager: ";
        cin >> wager;

        if (wager > cash)
        {
            cout << "You don't have enough money to place a wager." << endl;
            continue;
        }

        do
        {
            cout << "Pick a number between 1 & 6: ";
            cin >> roll_num;
            if (roll_num < 1 || roll_num > 6)
            {
                cout << "Invalid number. Please enter again." << endl;
            }
        } while (roll_num < 1 || roll_num > 6);

        roll1 = dice_roll();
        roll2 = dice_roll();
        roll3 = dice_roll();

        int count = 0;

        if (roll1 == roll_num) 
        {
            count++;
        }

        if (roll2 == roll_num)
        {
            count++;
        }

        if (roll3 == roll_num)
        {
            count++;
        }

        if (count == 0)
        {
            cout << "No matches found. You lose the wager." << endl;
            cash -= wager;
        }

        else if (count == 1)
        {
            cout << "One match! You win one wager back!" << endl;
        }

        else if (count == 2)
        {
            cout << "Two matches! You win two times the wager!" << endl;
            cash += wager;
        }

        else if (count == 3)
        {
            cout << "Three matches! You win three times the wager!" << endl;
            cash += 2 * wager;
        }

        if (cash <= 0)
        {
            cout << "You are out of money:( /nGAME OVER" << endl;
            break;
        }

        cout << "Would you like to play again? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y' )
        {
            cout << "Thanks for playing!" << endl;
            cout << "You were left with $" << cash << endl;
            break;
        }

    }

    return 0;
}