#include <iostream>

using namespace std;

int main() {
    int number;
    int array[9] = { 0,0,0,0,0,0,0,0,0 };
    for (int i = 0; i <= 3295; i++) {

        cin >> number;
        while (number >= 10)
        {
            number = number / 10;
        }

        if (number == 1) {
            array[0] += 1;
        }
        if (number == 2) {
            array[1] += 1;
        }
        if (number == 3) {
            array[2] += 1;
        }
        if (number == 4) {
            array[3] += 1;
        }
        if (number == 5) {
            array[4] += 1;
        }
        if (number == 6) {
            array[5] += 1;
        }
        if (number == 7) {
            array[6] += 1;
        }
        if (number == 8) {
            array[7] += 1;
        }
        if (number == 9) {
            array[8] += 1;
        }

    }
    cout << endl << "There are " << array[0] << " numbers that start with one" << endl;
    cout << endl << "There are " << array[1] << " numbers that start with two" << endl;
    cout << endl << "There are " << array[2] << " numbers that start with three" << endl;
    cout << endl << "There are " << array[3] << " numbers that start with four" << endl;
    cout << endl << "There are " << array[4] << " numbers that start with five" << endl;
    cout << endl << "There are " << array[5] << " numbers that start with six" << endl;
    cout << endl << "There are " << array[6] << " numbers that start with seven" << endl;
    cout << endl << "There are " << array[7] << " numbers that start with eight" << endl;
    cout << endl << "There are " << array[8] << " numbers that start with nine" << endl;
}