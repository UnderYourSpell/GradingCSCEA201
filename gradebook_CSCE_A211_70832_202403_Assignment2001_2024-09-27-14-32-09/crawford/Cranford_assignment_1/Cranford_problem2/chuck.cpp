#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void rollingdice(int &d1, int &d2, int &d3) {
     d1 = rand() % 6 + 1;
     d2 = rand() % 6 + 1;
     d3 = rand() % 6 + 1;
}

int main() {
    srand(time(0));
    int balance = 100, bet, number, d1, d2, d3;
    char playagain;

    do {
        cout << "Your Balance: " << balance << "Enter bet: ";
        std::cin >> bet;
        while (bet > balance || bet <= 0) {
              cout << "Invalid bet. Enter a bet less than your balance and greater than 0: ";
              cin >> bet;
        }

       cout << "Pick a number:(1-6) ";
       cin >> number;
       while (number < 1 || number > 6) {
             cout << "Invalid Number. Pick between 1 and 6: ";
             cin >> number;
       }

       rollingdice(d1, d2, d3);
       cout << "Dice results: " << d1 << " " << d2 << " " << d3 << std::endl;

      int matches = (d1 == number) + (d2 == number) + (d3 == number);
      if (matches == 0) {
          balance -= bet;
         cout <<  "No match. Bet lost" << bet << endl;
      } else {
          balance += matches * bet;
          cout << "You have " << matches << " matches. You win." << matches *bet << endl;
      }

      if (balance > 0) {
          cout << "Play again? (y/n): ";
          cin >> playagain;
      } else {
          cout << "Balance is 0. Game Over." << endl;
      }

    } while (playagain == 'y' || playagain == 'Y');

  return 0;
}
