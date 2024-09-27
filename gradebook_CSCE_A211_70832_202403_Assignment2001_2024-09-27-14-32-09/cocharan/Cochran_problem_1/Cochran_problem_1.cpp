
#include <iostream>

int main() {

	// declare varibles "num" and "i"
	int num, i; //num is the input number, i is the itteration varible

	// declare the integer array nums_begin and initialise each position in it to 0
	// nums_begin will hold the number of numbers, for each digit from 1 to 9, that start with a cirtain digit
	int nums_begin[9] = {0};

	// read in 3295 numbers from the input
	for (i = 0; i < 3295; i++) {

		// read the next number
		std::cin >> num;

		// find the leading digit of that number by using integer division
		while (num > 9) {

			// perform integer division to remove the trailing digit
			num = num / 10;

		}

		// increment the amount of that number in nums_begin
		nums_begin[num - 1]++;

	}


	// spacing for output
	std::cout << std::endl;

	// print out header
	std::cout << "The amount of numbers that started with:" << std::endl;

	// print out how many of each digit was found.
	for (i = 0; i < 9; i++) {

		std::cout << "#" << (i + 1) << ": " << nums_begin[i] << std::endl;

	}

	// more spacing for fancy output
	std::cout << std::endl;

}
