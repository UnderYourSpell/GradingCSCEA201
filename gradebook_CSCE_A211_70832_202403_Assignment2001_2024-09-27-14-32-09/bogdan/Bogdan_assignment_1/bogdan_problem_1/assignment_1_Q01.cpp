#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{


	int myArray[10] = {0};

	string myValStr;
	string tempStr;
	int myVal = 0;

	//Will take inputs until EOF or input wrong data type
	//I.E. wrting string into int.    
	while (cin >> myValStr)
	{
		tempStr = myValStr[0];
		//cout << myValStr << endl;

		try {
			myVal = stoi(tempStr);
			
			myArray[myVal] += 1;
			//This throw catch is unnesecary 
			//throw (myValStr);
		    }
		catch (...)
		    {
			cout << "\nERROR: Failed to convert string to integer!" << endl;
			break;
		    }		

		//myArray[myVal % 10] += 1;
	}

	cout << " Number:\t Count:\t\t Percent: "  << endl;
	
	cout << setprecision(2) << fixed ;
	//Starts at index 1 as no leading digit starts with 0 (irrelevant data) 
	//Hard coded the %calculation should of implemented 
	//a counter to know how large the number pool was
	for (int i = 1; i < 10; i++)
	{
		cout << "\t" << i << "\t      #" << myArray[i] ;
		cout << "\t\t%" <<(float(myArray[i]) / 3295.0) * 100 << endl;	
	}

	return 0;
}
 
