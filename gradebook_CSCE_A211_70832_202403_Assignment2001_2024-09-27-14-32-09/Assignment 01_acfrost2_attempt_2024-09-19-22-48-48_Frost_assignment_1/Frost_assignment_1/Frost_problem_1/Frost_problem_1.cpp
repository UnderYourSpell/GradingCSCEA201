#include<iostream>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    int num1, num2, num3, num4, num5, num6, num7, num8, num9;
    string string_array[3295];
        for(int i= 0; i < 32; i++){
            cin >> string_array[i];
        }
    for (int i = 0; i < sizeof(string_array)/sizeof(string_array[0]); ++i)
        if (string_array[i].substr(0,1) == "1")
            num1++;
    for (int i = 0; i < sizeof(string_array)/sizeof(string_array[0]); ++i)
        if (string_array[i].substr(0,1) == "2")
            num2++;
    for (int i = 0; i < sizeof(string_array)/sizeof(string_array[0]); ++i)
        if (string_array[i].substr(0,1) == "3")
            num3++;
    for (int i = 0; i < sizeof(string_array)/sizeof(string_array[0]); ++i)
        if (string_array[i].substr(0,1) == "4")
            num4++;
    for (int i = 0; i < sizeof(string_array)/sizeof(string_array[0]); ++i)
        if (string_array[i].substr(0,1) == "5")
            num5++;
    for (int i = 0; i < sizeof(string_array)/sizeof(string_array[0]); ++i)
        if (string_array[i].substr(0,1) == "6")
            num6++;
    for (int i = 0; i < sizeof(string_array)/sizeof(string_array[0]); ++i)
        if (string_array[i].substr(0,1) == "7")
            num7++;
    for (int i = 0; i < sizeof(string_array)/sizeof(string_array[0]); ++i)
        if (string_array[i].substr(0,1) == "8")
            num8++;
    for (int i = 0; i < sizeof(string_array)/sizeof(string_array[0]); ++i)
        if (string_array[i].substr(0,1) == "9")
            num9++;
    cout <<"1: "<< num1<<endl;
    cout <<"2: "<< num2 <<endl;
    cout <<"3: "<< num3<<endl;
    cout <<"4: " <<num4<<endl;
    cout <<"5: "<< num5<<endl;
    cout << "6: "<<num6 <<endl;
    cout <<"7: "<< num7<<endl;
    cout <<"8: "<< num8<<endl;
    cout <<"9: "<< num9<<endl;
    return 0;
}
