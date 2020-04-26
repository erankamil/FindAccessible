#include "StackNode.h"

StackNode::StackNode(const ItemData& i_data,StackNode* i_next) :m_data(i_data)
{
	m_next = i_next;
}
const ItemData& StackNode::getItemData() const
{
	return m_data;
}

void StackNode::setItemData(const ItemData& i_data)
{
	m_data = i_data;
}
