// Critchfield_Problem_1.cpp : Write a C++ program that reads 3295 numbers from the console (i.e., you would normally type in the numbers) and outputs how many of those numbers start with 1, how many start with 2, etc. up to 9.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    const int totalNumbers = 3295;
    vector<int> counts(9, 0); // Array, store counts for digits 1-9
    string number;

    // Open the file
    ifstream inputFile("C:\\Users\\onacr\\source\\repos\\Critchfield_Problem_1\\Critchfield_Problem_1\\x64\\Debug\\Enrollments.txt");

    // Check if file failed to open
    if (!inputFile) {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    int numRead = 0;
    // Loop to read all the numbers from file
    while (inputFile >> number && numRead < totalNumbers) {
        // Remove any leading zeros
        int j = 0;
        while (j < number.size() && number[j] == '0') {
            j++;
        }

        // Check the first non-zero character and increment the corresponding counter
        if (j < number.size() && number[j] >= '1' && number[j] <= '9') {
            counts[number[j] - '1']++; // 1 corresponds to counts, 9 to counts 8
        }

        numRead++;
    }

    inputFile.close(); // Close the file

    // Output the counts for digits 1 to 9
    for (int i = 0; i < 9; ++i) {
        cout << "Numbers starting with " << (i + 1) << ": " << counts[i] << endl;
    }

    return 0;
}
