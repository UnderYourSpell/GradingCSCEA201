

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// get number between 1 and 6 inclusive
int rollDice();

// Check rolls vs guess and determine payout
double determinePayout(int r1, int r2, int r3, int guess, double wager, double cash);

int main()
{
    srand(time(NULL));

    double W;                   // wager
    int n;                      // player number between 1 - 6
    double cash = 100.00;       // player's current cash
    char key;                   // used to enter and exit game
    int roll_1, roll_2, roll_3; // store dice rolls

    // Play Game
    cout << "Welcome to CHUCK-A-LUCK\n\n";
    cout << "Would you like to play (y/n): ";
    cin >> key;
    cout << endl;

    while (key == 'y')
    {
        // Ensure user has cash to wager
        if (cash <= 0)
        {
            cout << "You are all out of cash!\n";
            return 1;
        }
        // Get wager, ensure valid
        cout << "Current cash: $" << fixed << setprecision(2) << cash << endl;
        cout << "Enter a wager: ";
        cin >> W; 
        while (W > cash || W <= 0)
        {
            cout << "Invalid wager!\n";
            cout << "Current cash: $" << fixed << setprecision(2) << cash << endl;
            cout << "Enter a wager: ";
            cin >> W;
        }

        // Get guess, ensure valid
        cout << "Enter a guess (1-6): ";
        cin >> n;
        while (n < 1 || n > 6)
        {
            cout << "Number must be between 1 and 6 inclusive: ";
            cin >> n;
        }
        cout << endl;

        // Get rolls
        roll_1 = rollDice();
        roll_2 = rollDice();
        roll_3 = rollDice();

        // Check win / loss
        cash = determinePayout(roll_1, roll_2, roll_3, n, W, cash);

        // Ensure user has cash to wager
        if (cash <= 0)
        {
            cout << "You are all out of cash!\n";
            return 1;
        }

        // Prompt to continue playing
        cout << "Current cash: $" << fixed << setprecision(2) << cash << endl;
        cout << "Play again (y/n)? ";
        cin >> key;
        cout << endl;
    }

    return 0;
}

// get number between 1 and 6 inclusive
int rollDice()
{
    return rand() % 6 + 1;
}

// Check rolls vs guess and determine payout
double determinePayout(int r1, int r2, int r3, int guess, double wager, double cash)
{
    int match_total = 0;
    if (r1 == guess)
        match_total++;
    if (r2 == guess)
        match_total++;
    if (r3 == guess)
        match_total++;

    switch (match_total)
    {
        case 0:
            cout << "None of the rolls " << r1 << ", " << r2 << ", " << r3 << " matched your guess " << guess << endl;
            cout << "You lost $" << wager << " cash\n";
            cash -= wager;
            break;

        case 1:
            cout << "Only one of the rolls " << r1 << ", " << r2 << ", " << r3 << " matched your guess " << guess << endl;
            cout << "You won your wager back $" << wager << endl;
            break;

        case 2:
            wager *= 2;
            cout << "Two of the rolls " << r1 << ", " << r2 << ", " << r3 << " matched your guess " << guess << endl;
            cout << "You won $" << wager << " cash\n";
            cash += wager;
            break;

        case 3:
            wager *= 3;
            cout << "All three rolls " << r1 << ", " << r2 << ", " << r3 << " matched your guess " << guess << endl;
            cout << "You won $" << wager << " cash\n";
            cash += wager;
            break;
    }      
    return cash;
}

