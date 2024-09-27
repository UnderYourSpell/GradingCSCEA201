#include <iostream>


//Needed for random number generation
#include <cstdlib>
#include <ctime>



using namespace std;


//Since array pass by reference writes 3 die rolls into array 
void rollDie(int x[], int y)
{
	for (int i = 0; i < y; i++)
	{
	x[i] = (1 + rand() % 6); 
	}
}

void checkInput(int x, int &myInput)
{
	switch(x){
          case 1:
		while (!(myInput >= 1 && myInput <= 6))
		{		
		if (myInput >= 1 && myInput <= 6)
			{
				break; 
			}
		else
			{
				cout <<"\nSorry but you must choose number between 1-6: " ; 
				cin >> myInput;
				
			}  
		}
	  case 2:
		while (!(myInput >= 1 && myInput <= 100))
		{		
			if (myInput >= 1 && myInput <= 100)
			{
				break; 
			}
			else
			{
				cout <<"\nSorry but you must choose number between 1-100: " ; 
				cin >> myInput;
				

			}
		}
	}	
}


void playGame()
{
	int myGuess, myWager;
	
	//Die needed for the game
	const int totalDie = 3;
	int check[totalDie];
	
	//Default start of $100
	int myTotal = 100;

	//bool to keep playing
	char keepPlayChar;
	bool keepPlayBool = 1;

	//myCount to keep track of how many die are the same
	int myCount = 0;

	while (myTotal > 0 && keepPlayBool != 0)
	{
		//Gets die guess for roll
		cout << "Please guess a side of the die (1-6): " ;
		cin >> myGuess;
		checkInput(1, myGuess);

		//Gets Wager and subtracts wager from total
		cout << "\nPlease input your wager $1-100 (Current Total: " << myTotal << "): " ;
		cin >>  myWager;
		checkInput (2, myWager);
		//myTotal -= myWager;

		rollDie(check, totalDie);

		for (int i = 0; i < totalDie; i++)
		{
			cout << "Your Guess: " << myGuess << "\t Die #" << i+1;
			cout << " is: " << check[i] << endl;  
			if (myGuess == check[i])
				myCount += 1;
		}
		//I went off the betting described from problem prompt
		switch (myCount){
			case 0: 
				cout << "\nSorry! You Guessed Zero Die Correctly, Better Luck Next Time." << endl; 
				myTotal = myTotal - myWager;
				break;
			case 1:
				// No money won or loss
				cout << "\nYou Guessed One Die Correctly, You Made Back Your Wager!" << endl;  
				//myTotal += myWager;
				break;
			case 2:
				cout << "\nYou Guessed Two Die Correctly, You Made Back TWICE Your Wager!!" << endl;  
				myTotal += (myWager * 2);
				break;
			case 3:
				cout << "\nYou Guessed THREE Die! You Made Back Triple Your Wager!!!" << endl;  
				myTotal += (myWager * 3);
				break;
			}
		cout <<"\nCongratulations you now have: $" << myTotal << " left."  << endl;
	
		cout <<"Would you like to play again (y\\n): " ;
		cin >> keepPlayChar;
	
		//TODO: Add check to keepPlayChar to ensure correct data type 
		if (keepPlayChar == 'y')
		{
			keepPlayBool = 1;
		}
		else if (keepPlayChar == 'n')
		{
			keepPlayBool = 0;
			cout << "\nThanks For Playing!" << endl;
		} 
		else 
		{	
			keepPlayBool = 0;
			cout << "\nWe will take that as you want to leave. . . " << endl;
			cout << "Have a day (Give us more money next time).\n" << endl;  	
		}	
		
		myGuess = 0;
	}	

}

int main()
{
	//Seeds number generator with ctime
	srand(time(NULL));
 

	cout << "\nWelcome to Chuck-A-Luck Casino!!" << endl;
	cout << "We'll get you started right away. Guess a " ;
	cout << "side of a die and a wager, if a die is the same " << endl;
	cout << "as your guess, you make back your money, more equal dies, more winning!"<< endl;
	cout << "You start off with $100 dollars, please lose it all(we are a casino after all).\n\n" << endl; 

	playGame();



return 0;
}
