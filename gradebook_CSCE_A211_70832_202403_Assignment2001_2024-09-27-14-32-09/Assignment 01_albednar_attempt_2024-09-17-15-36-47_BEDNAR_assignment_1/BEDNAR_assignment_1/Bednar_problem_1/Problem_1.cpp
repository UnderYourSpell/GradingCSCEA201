#include <iostream>

using namespace std;

//Function Declarations
void countAll(int a[], int count[], int n);

//Global Constant Variables
const int MAX = 10;
const int AMOUNT = 3295;

int main()
{
    int count[MAX] = { 0 };
    int a[AMOUNT];
    int c;

    //Isolate the first integer of an input, no checking for character strings due to the prescribed input being a list of integers
    for (int i = 0; i < AMOUNT; i++)
    {
        string input;
        cin >> input;

        a[i] = input[0] - '0';
    }
    
    countAll(a, count, AMOUNT);

    //output the count array
    for (int i : count)
        cout << i << " ";
}

//Makes an array that takes the first integer in every input and puts it on an array from 0 - 9
void countAll(int a[], int count[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        if (a[i] > 0 && a[i] < MAX)
            count[a[i]-1]++;
    }
}

