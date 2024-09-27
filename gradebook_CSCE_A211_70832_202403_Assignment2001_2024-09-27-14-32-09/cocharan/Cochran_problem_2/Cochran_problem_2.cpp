
// include statements
#include <iostream>
#include <ctime>
#include <random>


// ----- function headers -----

int getNum(int startRange, int endRange);

int getRollResults(int numberToCount, int numRolls = 1);

float getWager(float currentCash);

bool getYesOrNo();




// ----- main program -----


int main() {

	bool quit = false;

	float userCash = 100;
	float wager;

	int userNum;
	int rollsWon;



	// output the amount of cash the user has at the start of the program
        std::cout << "Your account: $" << userCash << std::endl;


	// main loop
	while(!quit) {


		// get the user's wager

		std::cout << "What is your wager?" << std::endl;

		wager = getWager(userCash);

		std::cout << "You wagered: $" << wager << std::endl << std::endl;


		// get the user's betting number

		std::cout << "What is your betting number?" << std::endl;

		userNum = getNum(1, 6);

		std::cout << "Your betting number:" << userNum << std::endl << std::endl;


		// roll the dice three times, store the amount of times userNum showed up in rollsWon.

		std::cout << "rolling the dice..." << std::endl << std::endl;

		rollsWon = getRollResults(userNum, 3);


		// add or subtract an amount based on how many times the user rolled their number.

		if (rollsWon > 0) {

			userCash = userCash + (wager * rollsWon);

			std::cout << "You rolled your number " << rollsWon << " times!" << std::endl;
			std::cout << "You won $" << (wager * rollsWon) << "!" << std::endl << std::endl;

		}
		else {

			userCash = userCash - wager;

			std::cout << "None of the rolls were your number." << std::endl;
			std::cout << "You lost $" << wager << std::endl << std::endl;

		}

		std::cout << "Your account: $" << userCash << std::endl << std::endl;

		// detect if the user has ran out of money, otherwise ask if they wish to play another round.

		if (userCash <= 0) {

			std::cout << "You are out of cash!" << std::endl;
			std::cout << "GAME OVER" << std::endl << std::endl;

			quit = true;

		}
		else {

			std::cout << "Do you wish to play another round?" << std::endl;

			quit = !getYesOrNo();

		}

	}

	std::cout << "Thanks for playing!" << std::endl << std::endl;

	return 0;

}




// ----- functions -----


/*

	Function getNum prompts the user for an integer on the range startRange to endRange.
The function then collects a valid integer input from the user and returns the inputed value
if the user inputed a valid value.

	-- If the value is not valid --

	If the inputed value is not on the range of startRange to endRange, the user will be
reprompted and then told to only enter values on the specified range.

	It the user enters a non-integer value or some other invalid input, the user will be
reprompted and then told they can only enter integer values.

*/
int getNum(int startRange, int endRange) {

	// declare internal function varibles

	int userVal;

	bool isInputValid = false;

	// loop until user enters a valid input
	while(!isInputValid) {

		std::cout << "Enter a whole number from " << startRange << " to " << endRange << ": ";

		try {

			std::cin >> userVal;

			isInputValid = true;


		}
		catch (...) {

			isInputValid = false;

		}

		std::cout << std::endl;

		// if the user entered invalid input, tell them it is invalid and why.
		if (!isInputValid) {

			std::cout << "Entered a non-integer, please only enter integers." << std::endl;
			std::cout << std::endl;

		}
		else if ((userVal < startRange) || (userVal > endRange)) {

			std::cout << "Entered number is out of range, please only enter integers on the range." << std::endl;
			std::cout << std::endl;

			isInputValid = false;

		}

	}

	return userVal;

}


/*

function getRollResults emulates the amount of times numberToCount is rolled when rolling numRolls amount of times.

The function takes two integer parameters, numberToCount and a default integer paramenter numRolls (set to 1 by default).

The function returns an integer value, numHits.

*/
int getRollResults(int numberToCount, int numRolls) {

	int numHits = 0;

	std::srand(std::time(0));

	for (int i = 0; i < numRolls; i++) {

		if ( ( ( std::rand() % 6 ) + 1 ) == numberToCount) {

			numHits++;

		}

	}

	return numHits;

}



/*

The function getWager takes the float currentCash and prompt the user to enter a value, userWager,
	until they enter a value smaller than currentCash.
the function then returns userWager.

*/
float getWager(float currentCash) {

        // declare internal function varibles

        float userWager;

        bool isInputValid = false;

        // loop until user enters a valid input
        while(!isInputValid) {

                std::cout << "Enter your wager: ";

                try {

                        std::cin >> userWager;

                        isInputValid = true;

                }
		catch (...) {

			isInputValid = false;

		}

                std::cout << std::endl;

                // if the user entered invalid input, tell them it is invalid and why
		if (!isInputValid) {

                        std::cout << "Entered a non-number, please only enter numbers." << std::endl;
                        std::cout << std::endl;

                }
	 	else if ((userWager < 0) || (userWager > currentCash)) {


                        std::cout << "Entered number is out of range, please only enter integers on the range." << std::endl;
                        std::cout << std::endl;

                        isInputValid = false;

                }

        }

	return userWager;

}


/*

	The function getYesOrNo prompts the user for a responce of y or n until they enter y, n, Y, or N.

	If the user enters invalid input they will be told so and reprompted.

	The function returns true if the user input was y or Y, and false if the user input was n or N.

*/
bool getYesOrNo() {

        // declare internal function varibles

        char userResponce;

        bool isInputValid = false;

        // loop until user enters a valid input
        while(!isInputValid) {

                std::cout << "Enter 'y' or 'n': ";

                try {

                        std::cin >> userResponce;

                        isInputValid = true;

                }
		catch (...) {

			isInputValid = false;

		}

                std::cout << std::endl;

                // if the user entered invalid input, tell them it is invalid and why.
                if (!isInputValid) {

                        std::cout << "Entered a non-charecter, please only enter charecters." << std::endl;
                        std::cout << std::endl;

                }
                else if ((userResponce != 'y') && (userResponce != 'n') && (userResponce != 'Y') && (userResponce != 'N')) {

			std::cout << userResponce << " is not a valid responce." << std::endl;
                        std::cout << "Please only enter 'y' or 'n'." << std::endl;
                        std::cout << std::endl;

                        isInputValid = false;

                }

		std::cin.clear(); // clear input in case user entered something like "Yes" or "No".

	}

	// return true if user entered y or Y, otherwise return false if the user entered  n or N.

	if ((userResponce == 'y') || (userResponce == 'Y')) {

		return true;

	}
	else if ((userResponce == 'n') || (userResponce == 'N')) {

		return false;

	}

	return false;

}
