#include <iostream>


//Needed to format output
#include <iomanip>
using namespace std;




void printChange(int x, int q, int d, int n, int p)
{
	cout << "Change Given: " << x << endl;

	cout <<"Change Dispensed:" << endl;
	cout << "\t\tQuarter:" << setw(2) << q << endl;
	cout << "\t\tDime:\t" << setw(2) << d << endl;
	cout << "\t\tNickle:\t" << setw(2) << n << endl;
	cout << "\t\tPennie:\t" << setw(2) << p << endl;

}  


void makeChange(int change, int &quarter, int &dime, int &nickle, int &pennie)
{
	//Need copy for change for printChange() 
	int changeCPY = change;

	quarter = change / 25;
	change = change % 25;

	dime = change / 10;
	change = change % 10;

	nickle = change / 5;
	change = change % 5;

	pennie = change;

	printChange(changeCPY, quarter, dime, nickle, pennie); 

}
int main()
{

	//Var initialization
	int myQuart, myDime, myNick, myPenn;
	int myChange;

	//test case #1
	cout << "\ntest case #1" << endl;	
	myChange = 63;
	makeChange(myChange, myQuart, myDime, myNick, myPenn);

	//test case #2
	cout <<  "\ntest case #2" << endl;
	myChange = 42;
	makeChange(myChange, myQuart, myDime, myNick, myPenn);


	//user test case
	cout << "\nPlease enter your change: " ;
	cin >> myChange;
	if (myChange >= 1 && myChange <=99)
	{
		makeChange(myChange, myQuart, myDime, myNick, myPenn);
	}
	else
	{
		while (!(myChange >= 1 && myChange <=99))
		{
			cout << "Please enter change value between 1-99: " ;
			cin >> myChange;	
		}
		makeChange(myChange, myQuart, myDime, myNick, myPenn);
	}



	//cout << "Change Given: " << myChange << endl;

	//cout <<"\nChange Dispensed:" << endl;
	//cout << "Quarter:" << setw(2) << myQuart << endl;
	//cout << "Dime:\t" << setw(2) << myDime << endl;
	//cout << "Nickle:\t" << setw(2) << myNick << endl;
	//cout << "Pennie:\t" << setw(2) << myPenn << endl;



return 0;
}

