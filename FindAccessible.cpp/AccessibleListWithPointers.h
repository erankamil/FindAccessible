#ifndef _ACCSSIBLE_LIST_WITH_POINTERS_H
#define _ACCSSIBLE_LIST_WITH_POINTERS_H

#include <iostream>
using namespace std;
#include "AccessibleListNodeWithPointers.h"

class accessibleListWithPointers
{
private:
	accessibleListNodeWithPointers* m_head;
	accessibleListNodeWithPointers* m_tail;
public:
	accessibleListWithPointers();
	~accessibleListWithPointers();

	// gets
	accessibleListNodeWithPointers* getHead(); // First
	accessibleListNodeWithPointers* getTail(); // Last

	//methodes
	void makeEmpty();
	bool isEmpty();
	accessibleListNodeWithPointers* find(int i_computerName);
	void deleteNode(int i_computerName);
	void insertAfter(int i_computerName, int i_computerNameToInsertAfter);
	void insertToHead(int i_computerName);
	void insertToTail(int i_computerName);

	void Print() const;
};

#endif // _ACCSSIBLE_LIST_WITH_POINTERS_H
