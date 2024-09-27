#include <iostream>

using namespace std;

int main() {

	int nums[9];
	int records = 3295;

	for (int i : nums)
		i = 0;
	
	for (int i = 0; i < records; i++) {
		int temp;
		cin >> temp;
		
		while (temp >= 10) {
			temp /= 10;
		}

		++nums[temp - 1];
	}

	for (int i = 0; i < 9; i++) {
		cout << "Number " << i + 1 << " appeared " << nums[i] << " times." << endl;
	}

	return 0;
}
