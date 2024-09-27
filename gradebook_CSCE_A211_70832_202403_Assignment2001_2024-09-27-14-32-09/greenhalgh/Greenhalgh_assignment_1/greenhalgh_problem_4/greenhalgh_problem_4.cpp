#include <iostream>
using namespace std;

void calculateChange(int change, int &quarters, int &dimes, int &nickels, int &pennies)
{
    quarters = change / 25;
    dimes = (change % 25) / 10;
    nickels = ((change % 25) % 10) / 5;
    pennies = (((change % 25) % 10) % 5);
}
void validateInput(int &change)
{
    while(change > 99 || change < 1)
    {
        cout << "Invalid input, please enter an amount of change (1-99): ";
        cin >> change;
    }
}
void displayChange(int quarters, int dimes, int nickels, int pennies)
{
    if(quarters != 0)
        cout << quarters << " quarters " << endl;
    if (dimes != 0)
        cout << dimes << " dimes " << endl;
    if (nickels != 0)
        cout << nickels << " nickels " << endl;
    if (pennies != 0)
        cout << pennies << " pennies " << endl;
}

int main()
{
    int change, quarters, dimes, nickels, pennies;
    for(int i = 0; i < 3; i++)
    {
        cout << "Enter an amount of change (1-99): ";
        cin >> change;
        validateInput(change);
        calculateChange(change, quarters, dimes, nickels, pennies);
        displayChange(quarters, dimes, nickels, pennies);
    }
    

}