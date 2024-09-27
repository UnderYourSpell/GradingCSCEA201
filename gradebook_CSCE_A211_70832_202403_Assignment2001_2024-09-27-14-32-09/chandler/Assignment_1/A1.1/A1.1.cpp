// A1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFile;
    
    string line;
    char x;

    int num;

    inFile.open(R"(C:\Users\Kavi\source\CompProgam2\Assignments\Assignment_1\A1.1\x64\Debug\enrollments.txt)");

    if (inFile) {
        cout << "file opened successfully" << endl;
    }
    else {
        cout << "file opening failed" << endl;
    }

    int arr[10] = {0};

    while (getline(inFile, line)) {

        if (!line.empty()) {
            x = line[0];
            num = x - '0';
            arr[num] += 1;
        }
    }

    inFile.close();

    for (int i = 0; i < 10; i++) {
        cout << i << "s : " << arr[i] << endl;
    }
}
