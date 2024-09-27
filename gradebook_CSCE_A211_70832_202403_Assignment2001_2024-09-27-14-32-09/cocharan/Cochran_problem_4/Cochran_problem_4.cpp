// include headers

#include <iostream>



// function headers

/*
        The function getUserNum takes two integers an input, startNum and endNum.
        The function prompts the user for an integer from startNum to endNum. if
the user enters a number outside the range of startNum to endNum, or a non-number,
the program will notify the user and reprompt them. When the user enters a valid
number, the program will store it in userNum and then return userNum.
        The function returns an integer value.
*/
int getUserNum(int startNum, int endNum);


/*
        The function convertChange takes an integer and four pointers to
integers as input.
        The function takes totalChange and finds out how many quarters,
dimes, nickels, and pennies can go into it in that order. It will store
these values in the locations that quartersPtr, dimesPtr, nickelsPtr, and
penniesPtr point to respectively.
        the function does not return anything.
*/
void convertChange(int totalChange, int* quartersPtr, int* dimesPtr, int* nickelsPtr, int* penniesPtr);



// main program

int main() {

	// --- Declare Varibles ---

	int totalChange;
	int quarters;
	int dimes;
	int nickels;
	int pennies;


	// ---- Test Case 1 ----

	// get the values for 597 cents in change

	convertChange(269, &quarters, &dimes, &nickels, &pennies);

	// print out the first example

	std::cout << "Converting 269 cents into change:" << std::endl;
	std::cout << "quarters: " << quarters << std::endl;
        std::cout << "dimes:    " << dimes    << std::endl;
        std::cout << "nickels:  " << nickels  << std::endl;
        std::cout << "pennies:  " << pennies  << std::endl;

	std::cout << std::endl;


	// ---- Test Case 2 ----

	// get the values for 9999 in change

	convertChange(9999, &quarters, &dimes, &nickels, &pennies);

        // print out the second example

        std::cout << "Converting 9999 cents into change:" << std::endl;
        std::cout << "quarters: " << quarters << std::endl;
        std::cout << "dimes:    " << dimes    << std::endl;
        std::cout << "nickels:  " << nickels  << std::endl;
        std::cout << "pennies:  " << pennies  << std::endl;

        std::cout << std::endl;


	// ---- User Section ----

	// --- get the total amount of change from user ---

	std::cout << "Enter the amount in cents to convert to change:" << std::endl;

	totalChange = getUserNum(1, 99);


	// --- convert the change into quarters, dimes, nickels, and pennies

	convertChange(totalChange, &quarters, &dimes, &nickels, &pennies);


	// --- print out the number of quarters, dimes, nickels, and pennies

        std::cout << "Converting " << totalChange << " cents into change:" << std::endl;
        std::cout << "quarters: " << quarters << std::endl;
        std::cout << "dimes:    " << dimes    << std::endl;
        std::cout << "nickels:  " << nickels  << std::endl;
        std::cout << "pennies:  " << pennies  << std::endl;

	return 0;

}

/*
	The function getUserNum takes two integers an input, startNum and endNum.
	The function prompts the user for an integer from startNum to endNum. if
the user enters a number outside the range of startNum to endNum, or a non-number,
the program will notify the user and reprompt them. When the user enters a valid
number, the program will store it in userNum and then return userNum.
	The function returns an integer value.
*/
int getUserNum(int startNum, int endNum) {

	int userNum;

	bool validInput = false;

	// loop until input is valid
	do {

		std::cout << "Enter a whole number from " << startNum << " to " << endNum << ":" << std::endl;

		// get a whole number from startNum to endNum from the user
		try {
			std::cin >> userNum;

			// if the user enters a value outside the range of startNum to endNum, reprompt the user.
			if ((userNum >= startNum) && (userNum <= endNum)) {

				validInput = true;

			}
			else {

				std::cout << "Please only enter whole number values within the range." << std::endl;

				validInput = false;

			}

			std::cout << std::endl;

		}
		// if the user didn't enter a whole number, tell them to and reprompt for input
		catch(...) {

			std::cout << std::endl;
			std::cout << "Please only enter whole numbers." << std::endl;

			validInput = false;

		}

		std::cout << std::endl;

	}
	while(!validInput);

	return userNum;

}


/*
	The function convertChange takes an integer and four pointers to
integers as input.
	The function takes totalChange and finds out how many quarters,
dimes, nickels, and pennies can go into it in that order. It will store
these values in the locations that quartersPtr, dimesPtr, nickelsPtr, and
penniesPtr point to respectively.
	the function does not return anything.
*/
void convertChange(int totalChange, int* quartersPtr, int* dimesPtr, int* nickelsPtr, int* penniesPtr) {

	// find the number of quarters
	*quartersPtr = totalChange / 25;

	// subtract the quarters from totalChange
	totalChange -= ((*quartersPtr) * 25);


	// find the number of dimes
        *dimesPtr = totalChange / 10;

        // subtract the dimes from totalChange
        totalChange -= ((*dimesPtr) * 10);


	// find the number of nickels
	*nickelsPtr = totalChange / 5;

	// subtract nickels from totalChange
	totalChange -= ((*nickelsPtr) * 5);


	// find the number of pennies by using the remainder of totalChange
        *penniesPtr = totalChange;

}
