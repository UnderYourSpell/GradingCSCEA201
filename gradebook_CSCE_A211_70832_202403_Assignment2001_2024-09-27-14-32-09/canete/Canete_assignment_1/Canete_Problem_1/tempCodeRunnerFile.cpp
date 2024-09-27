#include <iostream>
#include <string>
using namespace std;

int main() {
    int onethroughnine[10] = {0}; // Initialize counts for digits 1-9
    string num;

    while (cin >> num) {
        char first = num[0];
        if (first >= '1' && first <= '9') {
            onethroughnine[first - '0']++;
        }
    }

    for (int i = 1; i < 10; i++) {
        cout << "Numbers starting with " << i << ": " << onethroughnine[i] << endl;
    }

    return 0;
}
