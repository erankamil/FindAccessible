#ifndef __ITEM_DATA_H
#define __ITEM_DATA_H

#include <iostream>
using namespace std;
#include "AccessibleListNodeWithPointers.h"
#define START 1
#define SECONED 2

class ItemData
{
private:

	int m_sourceComputer;
	int m_line;
	accessibleListNodeWithPointers* m_currentNode;

public:
	ItemData(int i_sourceComputer, accessibleListNodeWithPointers* i_currentNode ,int i_line);
	 // we didnt implement the copy,dtor since the class doesnt allocate memory 

	// gets
	int getComputerName() const ;
	int getLine() const;
	accessibleListNodeWithPointers* getCurrentNode()const;
	//sets
	void setComputerName(int i_sourceComputer);
	void setLine(int i_line);
	void setCurrentNode(accessibleListNodeWithPointers* i_newNode);



	
};
#endif // !__ITEM_DATA_H