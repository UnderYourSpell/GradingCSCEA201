#include <iostream>
#include <cmath>
using namespace std;

void coins (int change, int &quarter,int &dime, int &nickel,int &pennies ){
    if(change >= 25){
        quarter = floor(change/25) ;
        change = change % 25;
    }
    if(change >= 10){
        dime = floor(change/10);
        change = change % 10;
    }
    if(change >= 5){
        nickel = floor(change/5);
        change = change % 5;
    }
    pennies = change;
}


int main(){
    int quarter = 0, dime = 0 , nickel = 0, pennies = 0;
    int change;

    //test case 1
    cout << "How much change do you have:\n";
    //cin >> change; remove to make it user driven
    change = 98;
    while(change < 1 || change > 99){
        cout << "not within the ranges of 1-99 try again: ";
        cin >> change;
    }
    coins(change,quarter,dime,nickel,pennies);

    cout << "For " << change << " cents, the lowest amount of coins needed would be\n";
    cout << quarter << " quarters\n";
    cout << dime << " dimes\n";
    cout << nickel << " nickel\n";
    cout << pennies << " pennies\n\n";
    
    //test case 2
    quarter = 0, dime = 0 , nickel = 0, pennies = 0; //resetting to make the 0 again just in case

    cout << "How much change do you have:\n";
    change = 52;
    while(change < 1 || change > 99){
        cout << "not within the ranges of 1-99 try again: ";
        cin >> change;
    }
    coins(change,quarter,dime,nickel,pennies);

    cout << "For " << change << " cents, the lowest amount of coins needed would be\n";
    cout << quarter << " quarters\n";
    cout << dime << " dimes\n";
    cout << nickel << " nickel\n";
    cout << pennies << " pennies\n";
}