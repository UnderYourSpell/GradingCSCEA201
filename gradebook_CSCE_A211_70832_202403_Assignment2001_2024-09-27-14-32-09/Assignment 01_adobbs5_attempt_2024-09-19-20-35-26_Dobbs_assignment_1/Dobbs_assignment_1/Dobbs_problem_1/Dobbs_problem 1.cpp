#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> count(9, 0);  //store the count of leading digits 1-9
    int number;

    // Read 3295 numbers from the input 
    for (int i = 0; i < 3295; i++) {
        cin >> number;
        while (number >= 10) {
            number /= 10;  // the leading digit
        }
        if (number >= 1 && number <= 9) {
            count[number - 1]++;  // Increment count for the leading digit
        }
    }

    // Output
    for (int i = 0; i < 9; i++) {
        cout << "Leading digit " << i + 1 << ": " << count[i] << " occurrences" << endl;
    }

    return 0;
}
