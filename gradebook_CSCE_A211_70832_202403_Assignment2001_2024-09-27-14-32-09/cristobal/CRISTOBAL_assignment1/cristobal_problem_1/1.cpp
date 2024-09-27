#include <iostream>
#include <string>
using namespace std;

int main() 
{
    const int total_numbers = 3295;  
    int count[9] = {0};              
    string number;                   

    
    for (int i = 0; i < total_numbers; ++i) 
    {
        cin >> number;
        
        char first_char = number[0];
        
        
        if (first_char >= '1' && first_char <= '9') 
        {
            int digit = first_char - '0';  
            count[digit - 1]++;            
        }
    }

    
    for (int i = 0; i < 9; ++i) 
    {
        cout << "Numbers starting with " << i + 1 << ": " << count[i] << endl;
    }

    return 0;
}
