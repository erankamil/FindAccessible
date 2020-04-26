#include "AccessibleListNodeWithPointers.h" 

accessibleListNodeWithPointers::accessibleListNodeWithPointers(int i_computerName)
{
	this->m_computerName = i_computerName;
	this->m_next = nullptr;
}

accessibleListNodeWithPointers::accessibleListNodeWithPointers(const accessibleListNodeWithPointers& i_other)
{
	this->m_computerName = i_other.m_computerName;
	this->m_next = i_other.m_next;
}

accessibleListNodeWithPointers* accessibleListNodeWithPointers::getNext() const
{
	return this->m_next;
}
int accessibleListNodeWithPointers::getComputerName() const
{
	return this->m_computerName;
}


