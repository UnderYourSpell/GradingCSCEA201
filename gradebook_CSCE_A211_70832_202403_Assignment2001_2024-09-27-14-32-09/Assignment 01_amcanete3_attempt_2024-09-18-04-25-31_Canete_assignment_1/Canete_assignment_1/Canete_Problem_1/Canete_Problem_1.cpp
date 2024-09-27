#include <iostream>
#include <string>

using namespace std;

int main() {
    int counts[9] = {0};
    string number;

    while (cin >> number) {
        if (!number.empty()) {
            char leadingChar = number[0];
            if (leadingChar >= '1' && leadingChar <= '9') {
                int leadingDigit = leadingChar - '1';
                counts[leadingDigit]++;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        cout << "Count of numbers starting with " << (i + 1) << ": " << counts[i] << endl;
    }

    return 0;
}
