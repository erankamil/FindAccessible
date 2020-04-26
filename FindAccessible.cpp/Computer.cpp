#include "Computer.h"

computer::computer(int i_computerName, int i_maxOfAccessibleComputers) 
	: m_accessibleList()
{
	m_computerName = i_computerName;
}
accessibleListWithPointers& computer:: getAccessibleList()
{
	return m_accessibleList;
}

const int computer::getComputerName()const
{
	return this->m_computerName;
}

void computer::PrintAccessibleList() const
{
	m_accessibleList.Print();
}
