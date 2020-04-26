#pragma warning (disable: 4996)
using namespace std;
#include <iostream>
#include "System.h"
#include "AccessibleListWithPointers.h"

void isValidInput(int i_NameComptuer, int i_numOfComputers);

void main()
{
	int numOfComputers, numOfPairs;
	cin >> numOfComputers;
	cin >> numOfPairs;
	int sourceComputer, destComputer;
	System System(numOfComputers);
	for (int i = 0; i < numOfPairs; i++)
	{
		cin >> sourceComputer;
		isValidInput(sourceComputer, numOfComputers);// check valid input
		cin >> destComputer;
		isValidInput(destComputer, numOfComputers); // check valid input
		System.addPair(sourceComputer, destComputer);
	}
	int sourceComputerToFindAccessibleListFor; // the computer that got the massage
	cin >> sourceComputerToFindAccessibleListFor;
	isValidInput(sourceComputerToFindAccessibleListFor, numOfComputers);

	//call the recursive function 
	accessibleList accessibleListFromRec = System.findAccessibleListVersion1(sourceComputerToFindAccessibleListFor);
	//call the iterative function 
	accessibleList accessibleListFromIter = System.findAccessibleListVersion2(sourceComputerToFindAccessibleListFor);

	accessibleListFromRec.Print();
	cout << "\n";
	accessibleListFromIter.Print();
	system("pause");
}

//the function check if the name of the computer is valid 
void isValidInput(int i_NameComptuer,int i_numOfComputers)
{
	if (i_NameComptuer > i_numOfComputers || i_NameComptuer < 1)
	{
		cout << "no such computer " << i_NameComptuer;
		exit(1);
	}
}
