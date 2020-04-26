#ifndef _ACCESSIBLE_LIST_H
#define _ACCESSIBLE_LIST_H

#include <iostream>
using namespace std;
#include "AccessibleListNode.h"


class accessibleList
{
private:
	int m_physicalSize;
	int m_headList;
	int m_headFree;
	int m_listTail;
	accessibleListNode* m_arrList;

public:
	accessibleList(int i_maxOfAccessibleComputers);
	accessibleList(const accessibleList& i_other);
	~accessibleList();
	

	//gets
	 accessibleListNode* getArr() ;
	const int getHeadFree() const;
	const int getHeadList() const;

	//methodes
	void MakeEmpty();
	bool isEmpty() const;
	int First() const ;
	int Last() const;
	int Find(int i_computerNameToFind);
	void InsertAfter(int i_indexToInsertAfter, int i_computerToInsert);
	void InsertToHead(int i_computerToInsert);
	void InsertToTail(int i_computerToInsert);
	accessibleListNode& DeleteAfter(int i_indexToDeletetAfter);
	void Print() const;
};
#endif // _ACCESSIBLE_LIST_H

