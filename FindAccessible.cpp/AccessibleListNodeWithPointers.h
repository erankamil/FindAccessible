#ifndef _ACCSSIBLE_LIST_NODE_WITH_POINTERS_H
#define _ACCSSIBLE_LIST_NODE_WITH_POINTERS_H

#include <iostream>

class accessibleListNodeWithPointers
{

private:
	accessibleListNodeWithPointers* m_next;
	int m_computerName;
public:
	accessibleListNodeWithPointers(int i_computerName);
	accessibleListNodeWithPointers(const accessibleListNodeWithPointers& i_other);

	// gets
	accessibleListNodeWithPointers* getNext() const;
	int getComputerName() const;
	
	friend class accessibleListWithPointers;
};

#endif // _ACCSSIBLE_LIST_NODE_WITH_POINTERS_H

