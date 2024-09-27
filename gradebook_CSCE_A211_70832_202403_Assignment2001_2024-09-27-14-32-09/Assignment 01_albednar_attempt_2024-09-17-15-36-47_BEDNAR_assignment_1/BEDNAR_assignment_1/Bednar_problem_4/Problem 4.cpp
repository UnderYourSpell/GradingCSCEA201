//Include Libraries 
#include <iostream>

using namespace std; 

//Declare functions
void sortChange(int, int&, int&, int&, int&);

int main()
{
    int change;
    int pennies = 0, nickels = 0, dimes = 0, quarters = 0;

    cout << "How much change do you have?" << endl << "c";
    cin >> change;

    sortChange(change, pennies, nickels, dimes, quarters);

    cout << "\nQuarters: " << quarters << endl
        << "Dimes: " << dimes << endl
        << "Nickels: " << nickels << endl
        << "Pennies: " << pennies << endl;

    return 0;

}

//Sort the change and count the minimum pennies, nickels, dimes, and quarters required in order to give it.
void sortChange(int c, int& p, int& n, int& d, int& q)
{
    int change = c;
    
    //Run through division and modulo to lower the change value and get the MOST amount of the highest coins available
    q = change / 25;
    change %= 25;

    d = change / 10;
    change %= 10;

    n = change / 5;
    change %= 5;

    p = change / 1;
    
    return;
}

