#include <cstdlib>
#include<iostream>
#include <limits>

using namespace std;
void change(int money, int &quarters, int &dimes, int& nickels, int& pennies) {
    quarters = money/25;
    money-=quarters*25;
    dimes = money/10;
    money-=dimes*10;
    nickels = money/5;
    money-=nickels*5;
    pennies = money;
    money-=pennies;
}
int main(){
    int money = 69, quarters, dimes,nickels, pennies;
    cout << "First we will test 69 cents.\n";
    change(money, quarters, dimes, nickels, pennies);
    cout << money << " cents gets you " << quarters << " quarters, " << dimes << " dimes, and " << pennies << " pennies.\n";
    money = 49;
    cout <<"Now we will test 24 cents.\n";
    change(money, quarters, dimes,nickels, pennies);
    cout << money << " cents gets you " << quarters << " quarters, " << dimes << " dimes, and " << pennies << " pennies.\n";
    return 0;
}
