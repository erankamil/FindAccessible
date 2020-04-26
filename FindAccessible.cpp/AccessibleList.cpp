#include "AccessibleList.h"

accessibleList::accessibleList(int i_maxOfAccessibleCumputers)
{
	m_headFree = 0;
	m_headList = m_listTail=-1;
	m_physicalSize = i_maxOfAccessibleCumputers;
	m_arrList = new accessibleListNode[i_maxOfAccessibleCumputers];
	for (int i = 0; i < i_maxOfAccessibleCumputers - 1; i++)
	{
		m_arrList[i].m_next = i + 1; // initialize the empty list 
	}
	m_arrList[i_maxOfAccessibleCumputers - 1].m_next = -1; // end of list
}
accessibleList::accessibleList(const accessibleList& other)
{
	m_headFree = other.m_headFree;
	m_headList = other.m_headList;
	m_physicalSize = other.m_physicalSize;
	m_arrList = new accessibleListNode[m_physicalSize];
	for(int i=0;i< m_physicalSize;i++)
		m_arrList[i] = other.m_arrList[i];
}
accessibleList::~accessibleList()
{
	delete[]m_arrList;
}
 accessibleListNode* accessibleList::getArr() 
{
	return m_arrList;
}
const int accessibleList::getHeadFree() const
{
	return m_headFree;
}
const int accessibleList::getHeadList() const
{
	return m_headList;
}
void accessibleList::MakeEmpty()
{
	m_headFree = 0;
	m_headList = -1;
	for (int i = 0; i < m_physicalSize - 1; i++)
	{
		m_arrList[i].m_next = i + 1; // initialize the empty list 
	}
	m_arrList[m_physicalSize - 1].m_next = -1; // end of list
}
bool accessibleList::isEmpty() const
{
	if (m_headList)
		return false;
	return true;
}
int accessibleList::First() const 
{
	return m_headList;
}
int  accessibleList::Last() const
{
	int currentIndex = m_headList;
	int prevIndex=-1;
	while (currentIndex != -1)
	{
		prevIndex = currentIndex; // using prevIndex to return the last value
		currentIndex = m_arrList[currentIndex].m_next;
	}
	return prevIndex;
}
void accessibleList::InsertAfter(int i_indexToInsertAfter,int i_computerToInsert)
{ // the function inserts new computer after the index to insert after
	int location = m_headFree; // the first index that is free
	m_headFree = m_arrList[m_headFree].m_next; // update the headfree index
	m_arrList[location].m_computerName = i_computerToInsert; 
	m_arrList[location].m_next = m_arrList[i_indexToInsertAfter].m_next; 
	m_arrList[i_indexToInsertAfter].m_next = location;
}

// add new computer to head of the list
void accessibleList::InsertToHead(int i_computerToInsert)
{ 
	int location = m_headFree;// location of the new computer
	m_headFree = m_arrList[m_headFree].m_next;
	m_arrList[location].m_computerName = i_computerToInsert;
	m_arrList[location].m_next = m_headList;
	m_headList = location;
}
void accessibleList::InsertToTail(int i_computerToInsert)
{
	int location = m_headFree;// location of the new computer
	m_arrList[location].m_computerName = i_computerToInsert;
	m_headFree = m_arrList[m_headFree].m_next;
	m_arrList[location].m_next = -1;

	if (m_headList == -1)//the list is now empty
	{
		m_headList = location;
	}
	else
	{
		m_arrList[m_listTail].m_next = location;
		
	}
	m_listTail = location; // update the new tail
}
// the function deletes the node located after the index to delete
accessibleListNode& accessibleList::DeleteAfter(int i_indexToDeletetAfter)
{
	int indexToDelete = m_arrList[i_indexToDeletetAfter].m_next;

	// update the next member
	m_arrList[i_indexToDeletetAfter].m_next = m_arrList[indexToDelete].m_next;

	// update the next of the node we want to delete
	m_arrList[indexToDelete].m_next = m_headFree;

	// update the headfree
	m_headFree = indexToDelete;
	return m_arrList[indexToDelete];
}
int accessibleList::Find(int i_computerNameToFind)
{
	int current_index = m_headList; // set the current index to the head of the list
	while (current_index != -1 && (m_arrList[current_index].m_computerName != i_computerNameToFind))
	{
		current_index = m_arrList[current_index].m_next;
	}
	return current_index;
}
// the function prints the computer names in the accessible list 
void accessibleList::Print() const
{ 
	int currentComputerIndex = m_headList;
	if (currentComputerIndex == -1)
	{
		cout << "LIST IS EMPTY \n";
	}
	while (currentComputerIndex != -1)
	{
		cout << m_arrList[currentComputerIndex].m_computerName<<" ";
		currentComputerIndex = m_arrList[currentComputerIndex].m_next;
	}
}

