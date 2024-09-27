#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

//FUNCTION DECLARATIONS
int rollD6();
int getOption(string, int, int);
bool gameLoop(int&);
void printRules();

int main()
{
	srand(time(NULL));

	int money = 100;
	int round = 0;

	// Introduction / Display Rules

	char displayRulesChar;
	cout << "\nWelcome to Tony's Casino, do you need the rules for Chuck-a-Luck or do you already know how to play(y/n)? ";
	cin >> displayRulesChar;

	if (displayRulesChar == 'Y' || displayRulesChar == 'y')
		printRules();
	else
		cout << "\nThen let's get to it. I have some $ to make." << endl;

	cout << "\n(You have $" << money << ')' << endl;

	bool shouldContinue;

	do
	{
		round++;
		cout << "\n==ROUND " << round << "==\n" << endl;
		shouldContinue = gameLoop(money);
	} while (shouldContinue);

	if (money > 0)
		cout << "\n(You escaped with $" << money << ")\n" << endl;

	return 0;
}

bool gameLoop(int& money)
{
	// Enter Wager

	string wagerMessage = "What's your wager ($)? ";
	int wager = getOption(wagerMessage, 1, money);
	money -= wager;

	// Pick a number from 1-6

	string guessMessage = "What's your guess (1-6)? ";
	int guess = getOption(guessMessage, 1, 6);

	// Roll 3 d6

	cout << endl;

	int correctGuesses = 0;

	for (int i = 0; i < 3; i++)
	{
		int currentRoll = rollD6();
		cout << "Roll " << i + 1 << ": " << currentRoll << endl;
		if (currentRoll == guess)
		{
			correctGuesses++;
		}
	}

	// Check results

	cout << endl;

	cout << "Correct Guesses: " << correctGuesses << endl;

	cout << endl;

	if (correctGuesses > 0)
	{
		int winnings = wager * correctGuesses;
		money += winnings;
		cout << "Nice job kiddo, here's your $." << endl;
		cout << "(You won " << correctGuesses << "x your wager! ($" << winnings << "))" << endl;
	}
	else
	{
		cout << "Sorry buddy, should've guessed better." << endl;
		cout << "(You lost your wager...)" << endl;
	}

	// Check game state

	if (money > 0)
	{
		cout << "(You now have $" << money << ')' << endl;
	}
	else
	{
		//Exit Game
		cout << "You're out of $, beat it!" << endl;
		return false;
	}

	// Repeat or Exit

	cout << endl;

	char continueChar;
	cout << "Wanna play another round kid (y/n)? ";
	cin >> continueChar;

	return (continueChar == 'y' || continueChar == 'Y');
}

int rollD6()
{
	return (rand() % 6) + 1;
}

int getOption(string optionsMessage, int min, int max)
{
	int option;
	cout << optionsMessage;
	cin >> option;
	while (option > max || option < min)
	{
		cout << "Good try pal, that's not gonna work here..." << endl;
		cout << optionsMessage;
		cin >> option;
	}

	return option;
}

void printRules()
{
	cout << endl;
	cout << "First you place a wager ($) then you guess the value of the dice rolls." << endl;
	cout << "I'll roll 3 dice and if any of 'em match your guess you get some $." << endl;
	cout << "If 1 matches your guess you get your wager back, 2 you double it, 3 you triple it." << endl;
	cout << "And well if none of 'em match I keep your money." << endl;
	cout << "Not too hard right? Now let's get started..." << endl;
}
