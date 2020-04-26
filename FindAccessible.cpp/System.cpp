#include "System.h"
#include "Computer.h"


System::System(int i_sizeOfComputerArr)
{
	this->m_sizeOfComputerArr = i_sizeOfComputerArr;
	m_computerArr = new computer* [i_sizeOfComputerArr];

	for (int i = 0; i < i_sizeOfComputerArr; i++)
	{
		// initialize each computer* with name and size
		m_computerArr[i] = new computer(i + 1, i_sizeOfComputerArr-1);
	}
}
System::~System()
{
	for (int i = 0; i < m_sizeOfComputerArr; i++)
	{
		delete m_computerArr[i]; // free each pointer of computer
	}
	delete[]m_computerArr;
}

// the functiom adds the dest computers to the accessible list of the source computer
void System::addPair(int i_sourceComputer, int i_destComputer)
{ 
	m_computerArr[i_sourceComputer - 1]->getAccessibleList().insertToTail(i_destComputer);
}

// the function prints each computer in the network and his accessible list
void System::print()const
{ 
	for (int i = 0; i < this->m_sizeOfComputerArr; i++)
	{
		cout << "\nThe " << i+1 << " computer Accessible List  is :\n";
		this->m_computerArr[i]->PrintAccessibleList();
	}
}

// version 1 is a resucrive function to find the accessible group of the computer who got the massage
 accessibleList System::findAccessibleListVersion1(int i_sourceComputer)
{ 
	int* colorArr = new int[m_sizeOfComputerArr];
	
	// initialize the color array with WHITE(0)
	for (int i = 0; i < m_sizeOfComputerArr; i++) 
	{
		colorArr[i] = WHITE;
	}
	
	// initialize empty accessible list
	accessibleList accessibleListRes(m_sizeOfComputerArr); 

	// calling the recursive function
	findAccessibleListRec(colorArr, i_sourceComputer, accessibleListRes);
	delete[]colorArr;
	return accessibleListRes;
}
 
 // recursive functiom that fills up the accessible list of the group who got the massage 
void  System::findAccessibleListRec(int* i_colorArr, int i_sourceComputer, accessibleList& accessibleListRes)
{ 
	 // paint the source computer with black in the array
	i_colorArr[i_sourceComputer - 1] = BLACK;
	accessibleListNodeWithPointers* currentNode = m_computerArr[i_sourceComputer - 1]->getAccessibleList().getHead();
	accessibleListRes.InsertToTail(i_sourceComputer);
	
	while (currentNode) // looping over the accessible list of the current computer
	{
		int currentComputerName = currentNode->getComputerName();
		
		if (i_colorArr[currentComputerName - 1] == WHITE) // if we didnt visit this computer yet
		{
			findAccessibleListRec(i_colorArr, currentComputerName, accessibleListRes);
		}
		
		// moving to the next node in the accessible list
		currentNode = currentNode->getNext();
	}
}

 // version 2 function doing the same thing using stack and without recursive
accessibleList  System::findAccessibleListVersion2(int i_sourceComputer)
{
	int* colorArr = new int[m_sizeOfComputerArr];
	for (int i = 0; i < m_sizeOfComputerArr; i++) // initialize the color array with WHITE(0)
	{
		colorArr[i] = WHITE;
	}
	
	// initialize empty accessible list
	accessibleList accessibleListRes(m_sizeOfComputerArr); 
	
	// calling the iterative function
	findAccessibleListIterative(colorArr, i_sourceComputer, accessibleListRes); 
	delete[]colorArr;
	return accessibleListRes;
}


void  System::findAccessibleListIterative(int* i_colorArr,  int i_sourceComputer, accessibleList& i_accessibleListRes)
{
	Stack stack;
	accessibleListNodeWithPointers* currentNodeInList = m_computerArr[i_sourceComputer - 1]->getAccessibleList().getHead();
	ItemData currItem(i_sourceComputer, currentNodeInList, START);
	stack.push(currItem);

	while (!stack.isEmpty())
	{
		 ItemData currItem = stack.pop();
		
		//if the current computer is not in the list yet 
		if ((currItem.getLine() == START))
		{
			// paint the source computer with black in the array
			i_colorArr[currItem.getComputerName() - 1] = BLACK;

			// add the source computer to final accessible list 
			i_accessibleListRes.InsertToTail(currItem.getComputerName());
		}

		accessibleListNodeWithPointers* CurrentNode = currItem.getCurrentNode();
		if (CurrentNode) // we didnt finish the current computer accessible list 
		{
			//push the current computer with the updated index his accessible list
			int nextItemComputerName = CurrentNode->getComputerName();
			currItem.setCurrentNode(CurrentNode->getNext());
			currItem.setLine(SECONED);
			stack.push(currItem);

			if (i_colorArr[nextItemComputerName - 1] != BLACK) // we dont want the push computer that has been pushed already
			{
				accessibleListNodeWithPointers*  nextItemHeadList = m_computerArr[nextItemComputerName - 1]->getAccessibleList().getHead();
				ItemData nextItem(nextItemComputerName, nextItemHeadList, START);
				stack.push(nextItem);
			}
		}
	}
}
computer** System::getComputerNetworkArr()const
{
	return m_computerArr;
}
int System::getArrSize()const
{
	return m_sizeOfComputerArr;
}