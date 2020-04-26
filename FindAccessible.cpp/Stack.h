#ifndef _STACK
#define _STACK
#include <iostream>
using namespace std;
#include "StackNode.h"

class Stack
{
private:

	StackNode* m_top;

public:
	Stack(); 
	~Stack();

	//methodes
	void makeEmpty();
	bool isEmpty();
	void push(const ItemData& i_itemData);
	ItemData pop();
	const ItemData& top();
};
#endif // _STACK
