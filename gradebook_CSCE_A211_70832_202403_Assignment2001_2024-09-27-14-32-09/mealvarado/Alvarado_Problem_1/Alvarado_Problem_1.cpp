#include <iostream>
using namespace std;

int main() {
    int leadingDigitCount[10] = {0};
    int number;
    int totalCount;

    while (cin >> number) {
        while (number >= 10) {
            number /= 10;
        }
        if (number >= 1 && number <= 9) {
            leadingDigitCount[number]++;
            totalCount++;
        }
    }

    for (int i = 1; i <= 9; ++i) {
        double percentage = (leadingDigitCount[i] * 100.0) / totalCount;
        cout << "Digit " << i << ": " << percentage << "%" << endl;
    }
}

