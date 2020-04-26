#ifndef _COMPUTER_H
#define _COMPUTER_H

#include <iostream>
#include "AccessibleListWithPointers.h"



class computer
{
private:
	accessibleListWithPointers m_accessibleList;
	int m_computerName;
public:
	computer(int i_computerName,int i_maxOfAccessibleComputers);

	// gets
	accessibleListWithPointers& getAccessibleList();
	const int getComputerName()const;

	//methodes
	void PrintAccessibleList() const;
};

#endif // _COMPUTER_H
