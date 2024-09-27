#include <cstdlib>
#include <ctime>
#include<iostream>
#include <limits>

using namespace std;
void tumble(int &money, int &W) {
   int pick = 0, die1, die2, die3, wins;
   money -= W;
   while (pick < 1 || pick >6){
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout << "Pick a number between 1 and 6.\n";
     cin >> pick;
   }
   die1 = (rand()%6)+1;
   cout << "First roll: " << die1 << endl;
   die2 = (rand()%6)+1;
   cout << "Second roll: " << die2 << endl;
   die3 = (rand()%6)+1;
   cout << "Third roll: " << die3 << endl;
   if(die1 == pick)
        wins ++;
   if(die2== pick)
        wins ++;
   if(die3 == pick)
        wins ++;
   if(wins>0){
    cout << "You won " << wins << " times!\n";
   if(wins==3){
        cout<<"Wow! When you're hot, you're hot!\n";
    }}
   else{
    cout << "You didn't win... sucks to be you!\n";
   }
   money += W*wins;
    cout << "Now you have $" << money << endl;
}
int main(){
    srand((unsigned)time(0));
    int money =100, W;
    char play;
    while (play != 'n'){
        W = 0;
        play = 'x';
        cout <<"Would you like to play?\n";
        while (play != 'y' && play != 'n'){
        cout<<"Enter y or n.\n";
        cin >> play;
        }
        if(play == 'y'){
            cout <<"Oh really? Then gimme your wager, pardner.\n You currently have $" << money<<endl;
            if(money <= 0){
                cout <<"Yer out of luck. Get outta my casino!";
                abort();
            }
        while(W <= 0 || W > money){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout <<"Please enter a valid amount to wager: $";
            cin >> W;
        }
        tumble(money, W);

        }
        else{
            cout << "Smell ya later!\n";
            cout << "You left the casino with $" << money << ", pardner!";
            abort();
        }
    }
}
