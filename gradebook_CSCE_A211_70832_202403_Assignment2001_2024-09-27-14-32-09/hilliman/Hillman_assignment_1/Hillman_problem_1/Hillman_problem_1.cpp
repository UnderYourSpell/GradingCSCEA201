

#include <iostream>

using namespace std;

int main()
{
    char num[10]; // buffer for reading numbers
    const int file_total = 3295; // number of inputs to read from file

    int first_digit; // holds first digit from each input
    int first_digit_totals[10] = { 0 }; // store total number each input occurs

    // Count total number of each first digit
    for (int i = 0; i < file_total; i++)
    {
        cin >> num;

        first_digit = num[0] - '0'; // convert char to int value
        first_digit_totals[first_digit]++;
    }

    // Display results
    for (int i = 1; i < 10; i++)
    {
        cout << i << " totals: " << first_digit_totals[i] << endl;
    }
}


