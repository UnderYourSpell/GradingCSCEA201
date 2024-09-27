#include <iostream>
#include <cstdlib>

using namespace std;
int diceRoll()
{
    return (rand() % 6 + 1);
}
void isValidDice(int &userNum)
{
     while(userNum < 1 || userNum > 6)
     {
        cout << "Invalid choice, please try again. " << endl;
        cout << "Choose a dice number (1-6): ";
        cin >> userNum;
     }
}
void sufficientBalance(int userFunds, int &Wager)
{
    while(Wager > userFunds)
        {
            cout << "Insufficient balance, please change your wager. " << endl;
            cout << "Place a wager: $";
            cin >> Wager;
        }
}
void addMoney(int &userFunds, int Wager, int Counter)
{
    userFunds += (Wager * Counter);
}
void removeMoney(int &userFunds, int Wager)
{
    userFunds -= Wager;
}
void continuePlaying(char &userChoice, int userFunds)
{
    if(userFunds > 0)
    {
        cout << "Would you like to continue playing?" << endl;
        cout << "To continue, Please enter 'y' or 'Y'. Otherwise, enter 'n' or 'N'" << endl;
        cin >> userChoice;
        while(userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N')
        {
            cout << "Please enter a valid response. ";
            cout << "To continue, Please enter 'y' or 'Y'. Otherwise, enter 'n' or 'N'" << endl;
            cin >> userChoice;
        }
    }
}
int main()
{
    srand(time(NULL));
    int userFunds = 100;
    int Wager, userNum, rolledNum, wCounter;
    char userChoice;
    do{
        wCounter = 0;
        cout << "Current Funds: $" << userFunds << endl;
        cout << "Place a wager: $";
        cin >> Wager;

        sufficientBalance(userFunds, Wager);
        removeMoney(userFunds, Wager);
        
        cout << "Next, choose a dice number (1-6): ";
        cin >> userNum;

        isValidDice(userNum);

        for(int i = 1; i < 4; i++)
        {
            int rolledNum = diceRoll();
            cout << "You Rolled a " << rolledNum << endl;
            if(rolledNum == userNum)
            ++wCounter;
        }
        if(wCounter > 0)
        {
            cout << "You won $" << (wCounter * Wager) << "!" << endl;
            addMoney(userFunds, Wager, wCounter);
        }
        else
        cout << "You lost, better luck next time!" << endl;
        continuePlaying(userChoice, userFunds);
    }while((userChoice != 'n' && userChoice != 'N') && userFunds > 0);

    cout << "Thank you for playing!" << endl;
    return 0;
}