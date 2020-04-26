#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "Computer.h"
#include "AccessibleList.h"
#include "Stack.h"
#include <iostream>
using namespace std;

#define BLACK 1
#define WHITE 0


class System
{
private:
	int m_sizeOfComputerArr;
	computer** m_computerArr;

public:
	System(int i_sizeOfComputerArr);
	~System();
	System(const System& other) = delete; // forbid copy ctor

	 //gets
	 computer** getComputerNetworkArr()const;
	 int getArrSize()const;

//methodes
	void addPair(int i_sourceComputer, int i_destComputer);
	void print()const;
	 accessibleList findAccessibleListVersion1(int i_sourceComputer);
	 accessibleList  findAccessibleListVersion2(int i_sourceComputer);
private:
	void findAccessibleListRec(int* i_colorArr, int i_sourceComputer, accessibleList& i_accessibleListRes);
	void findAccessibleListIterative(int* i_colorArr, int i_sourceComputer, accessibleList& i_accessibleListRes);

};
#endif // _SYSTEM_H

