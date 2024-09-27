#include <iostream>

using namespace std;

int main()
{
	const int INPUT_COUNT = 3295;

	int inputs[9];

	for (int i = 0; i < INPUT_COUNT; i++)
	{
		char input[8];
		cin >> input;

		//I'm converting the char to the proper int using ASCII codes (1 = 49)
		inputs[(int)input[0] - 49]++;
	}

	for (int i = 0; i < 9; i++)
	{
		cout << i + 1 << ": " << ((float)inputs[i] / INPUT_COUNT) * 100 << '%' << endl;
	}

	return 0;
}
