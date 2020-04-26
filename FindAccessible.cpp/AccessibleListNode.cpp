#include "AccessibleListNode.h"

accessibleListNode::accessibleListNode(int i_computerName, int i_next)
{
	m_computerName = i_computerName;
	m_next = i_next;
}
accessibleListNode::accessibleListNode(const accessibleListNode& other)
{
	m_computerName = other.m_computerName;
	m_next = other.m_next;
}
int accessibleListNode::getNextIndex() const
{
	return m_next;
}
int accessibleListNode::getComputerName() const
{
	return m_computerName;
}