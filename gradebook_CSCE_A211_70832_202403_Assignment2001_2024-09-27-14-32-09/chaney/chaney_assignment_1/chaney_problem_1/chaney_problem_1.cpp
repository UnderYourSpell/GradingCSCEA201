#include <iostream>
#include <string>

using namespace std;

int main() {
    // Array to store counts for digits 1-9
    int counts[9] = {0};  // counts[0] is for '1', counts[1] is for '2', ..., counts[8] is for '9'
    string number;

    // Read each number from the input (redirected from the file)
    while (cin >> number) {
        // Skip any empty or invalid input
        if (number.empty()) {
            continue;
        }

        // Get the first character of the number string
        char leading_digit = number[0];

        // Convert the leading digit to an index (1 -> index 0, 2 -> index 1, ..., 9 -> index 8)
        if (leading_digit >= '1' && leading_digit <= '9') {
            int index = leading_digit - '1';  // Convert character to corresponding array index
            counts[index]++;  // Increment the count for the corresponding leading digit
        }
    }

    // Output the results
    for (int i = 0; i < 9; i++) {
        cout << "Count of numbers starting with " << (i + 1) << ": " << counts[i] << endl;
    }

    return 0;
}
