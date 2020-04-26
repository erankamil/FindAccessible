#include "AccessibleListWithPointers.h"


accessibleListWithPointers:: accessibleListWithPointers()
{
	this->m_head = this->m_tail = nullptr;
}
accessibleListWithPointers::~accessibleListWithPointers()
{
	makeEmpty(); // call makeEmpty fucntion to delete the allocate memory
}
accessibleListNodeWithPointers* accessibleListWithPointers::getHead()
{
	return this->m_head;
}
accessibleListNodeWithPointers* accessibleListWithPointers::getTail()
{
	return this->m_tail;
}

void accessibleListWithPointers::makeEmpty() 
{
	accessibleListNodeWithPointers* currNode = this->m_head, *temp;
	while (currNode) 
	{
		temp = currNode;
		currNode = currNode->m_next;
		delete temp; // delete each node in the list
	}
	m_head = m_tail = nullptr; // set the list to be empty
}

bool accessibleListWithPointers::isEmpty()
{
	if (!m_head) // the head=nullptr -> list empty
		return true;
	else
		return false;
}

// the function gets name of computer to find in the list
accessibleListNodeWithPointers* accessibleListWithPointers::find(int i_computerName)
{ 
	accessibleListNodeWithPointers* currNode = this->m_head;
	
	//runs over the list untuil we found the item or we finished the list
	while ((currNode) && (currNode->m_computerName != i_computerName)) 
	{
		currNode = currNode->m_next;
	}
		return currNode; // if we didnt find the item, currNode will be nullptr
}

//the function gets computer name to delete from the list
void accessibleListWithPointers::deleteNode(int i_computerName)
{
	accessibleListNodeWithPointers* currNode = this->m_head, *prev= nullptr,*nodeToDelete;

	if (isEmpty()) // check first if the list empty
	{
		cout << "EROR: THE LIST IS EMPTY, CANNOT DELETE.";
		exit(1);
	}

	//check if the item we want to delete is the head - delete from head of list
	if (this->m_head->m_computerName == i_computerName) 
	{
		nodeToDelete = m_head;
		this->m_head = this->m_head->m_next; // set the new head of the list

		if (!m_head) 
			m_tail = nullptr; // the list is empty now
	}
	
	//check if the item to delete is the tail of the list - delete from tail
	else if (this->m_tail->m_computerName == i_computerName) 
	{
		nodeToDelete = m_tail;
		while (currNode->m_next != m_tail) // get the node before the tail node
		{
			currNode = currNode->m_next;
		}
		m_tail = currNode; // update the tail of the list
		m_tail->m_next = nullptr;
	}

	else            // delete from inner place
	{
		// find the prev node and the node we want to delete
		while (currNode && (currNode->m_computerName != i_computerName))
		{
			prev = currNode;
			currNode = currNode->m_next;
		}
	
		if (!currNode) //the computer name is not in the list
		{
		cout << "EROR: THE COMPUTER IS NOT IN THE LIST, CANNOT DELETE.";
		exit(1);
		}

		nodeToDelete = currNode; 
		// set the next(pointer) of prev to the node after the node to delete
		prev->m_next = currNode->m_next; 
	}

	delete nodeToDelete; // delete the node 
}

// the function gets computer name(allocates it),and nsert to the list after the computer name she gets
void accessibleListWithPointers::insertAfter(int i_computerName, int i_computerNameToInsertAfter)
{
	accessibleListNodeWithPointers* currNode = this->m_head;
	accessibleListNodeWithPointers* newNode = new accessibleListNodeWithPointers(i_computerName);
	
	if (i_computerNameToInsertAfter == this->m_tail->m_computerName) // insert after tail
	{
		this->m_tail->m_next = newNode;
		this->m_tail = newNode;
	}
	else   // insert to inner place
	{
		while (currNode && (currNode->m_computerName != i_computerNameToInsertAfter))
		{
			currNode = currNode->m_next;
		}

		if (!currNode)// the name of computer to inert after doest exist in the list
		{
			cout << "EROR: THE COMPUTER IS NOT IN THE LIST, CANNOT INSERT AFTER.";
			exit(1);
		}
		
		newNode->m_next = currNode->m_next;
		currNode->m_next = newNode;
	}
}

//the function alloctes new node and inserts it to the head of the list
void accessibleListWithPointers::insertToHead(int i_computerName)
{
	
	accessibleListNodeWithPointers* newNode = new accessibleListNodeWithPointers(i_computerName);

	newNode->m_next = this->m_head;
	this->m_head = newNode;
	if (m_tail == nullptr)//list is empty
		m_tail - newNode;
}

//the function alloctes new node and inserts it to the tail of the list
void accessibleListWithPointers::insertToTail(int i_computerName)
{
	accessibleListNodeWithPointers* newNode = new accessibleListNodeWithPointers(i_computerName);
	if (isEmpty()) // list is empty
	{
		m_head = m_tail = newNode;
	}
	else // the list is not empty
	{
		this->m_tail->m_next = newNode;
		this->m_tail = newNode;
	}
}

void accessibleListWithPointers::Print() const
{
	accessibleListNodeWithPointers* currNode = this->m_head;

	while (currNode)
	{
		cout << currNode->m_computerName << " ";
		currNode = currNode->m_next;
	}

}