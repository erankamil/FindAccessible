#ifndef __STACK_NODE_H
#define __STACK_NODE_H

#include <iostream>
#include "ItemData.h"
using namespace std;

#define START 1
#define SECONED 2

class StackNode
{
private:
	ItemData m_data;
	StackNode* m_next;

public:
	StackNode(const ItemData& i_data,StackNode* i_next); 

	//get and sets
	const ItemData& getItemData() const;
	void setItemData(const ItemData& i_data);

	friend class Stack;
};
#endif // __STACK_NODE_H