#ifndef _ACCESSIBLE_LIST_NODE_H
#define _ACCESSIBLE_LIST_NODE_H

#include <iostream>

class accessibleListNode
{
private:
	int m_next;
	int m_computerName;
public:
	accessibleListNode() = default;
	accessibleListNode(int i_computerName, int i_next);
	accessibleListNode(const accessibleListNode& i_other);

	// gets
	int getNextIndex() const;
	int getComputerName() const;
	friend class accessibleList;
};

#endif // _ACCESSIBLE_LIST_NODE_H
