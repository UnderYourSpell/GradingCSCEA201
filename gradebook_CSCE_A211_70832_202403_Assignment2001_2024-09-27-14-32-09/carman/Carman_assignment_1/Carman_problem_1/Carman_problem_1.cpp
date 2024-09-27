#include <iostream>
#include <iomanip>
using namespace std;



int main() {

	int a[9] = { 0 };
	int input;
	int remaining = 0;
	double total = 0;

	cout << fixed << setprecision(2);

	while (cin >> input) {
		while (input != 0) {
			remaining = input % 10;
			input = input / 10;
		}
		remaining = remaining - 1;

		if (remaining >= 0 && remaining < 9) {
			a[remaining] += 1;
			total++;
		}
	}

	for (int i = 0; i < 9; i++) {
		cout << i + 1 << ":" << (a[i]/ total) * 100 << "%  ";
	}
	cout << endl;

}