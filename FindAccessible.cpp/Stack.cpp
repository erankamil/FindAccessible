#include "stack.h"

Stack::Stack() 
{
	m_top = NULL;
}
Stack::~Stack() 
{
	makeEmpty();
}
void Stack::makeEmpty()
{
	StackNode* temp;
	while (m_top != NULL)
	{
		temp = m_top;
		m_top = m_top->m_next;
		delete temp;
	}
}
bool Stack::isEmpty()
{
	return (m_top == NULL);
}
void Stack::push(const ItemData& i_itemData) // insert to stack
{
	m_top = new StackNode(i_itemData, m_top);
}
  ItemData Stack::pop() // delete from stack
{
	if (isEmpty())
	{
		cout << "Error:STACK UNDERFLOW\n";
		exit(1);
	}
	StackNode* temp = m_top;
	m_top = m_top->m_next;
	ItemData data = temp->m_data;
	delete temp;
	return data;
}
const ItemData& Stack::top() // show first in stack
{
	return m_top->m_data;
}