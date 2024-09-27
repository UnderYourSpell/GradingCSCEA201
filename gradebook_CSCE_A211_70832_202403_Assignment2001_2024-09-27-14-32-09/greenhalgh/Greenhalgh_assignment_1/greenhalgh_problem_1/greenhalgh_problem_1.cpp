#include <iostream>

using namespace std;

int firstDigitofNum(int num)
{
    while(num >= 10)
    {
        num /= 10;
    }
    return num;
}

int main()
{
    int count[9] = {0};
    int number, leadingNum;

    for(int i = 0; i < 3295; i++)
    {
        cin >> number;

        leadingNum = firstDigitofNum(number);
        count[leadingNum - 1]++;
    }
    for(int i = 0; i < 9; i++)
    {
        cout << "Percentage of numbers that starts with " << i+1 << ": " << (float(count[i]) / 3295) * 100 << "%" << endl;
    }
}