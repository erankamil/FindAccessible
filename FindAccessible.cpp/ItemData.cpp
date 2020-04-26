#include "ItemData.h"

ItemData::ItemData(int i_sourceComputer, accessibleListNodeWithPointers* i_currentNode, int i_line)
{
	m_sourceComputer = i_sourceComputer;
	m_currentNode = i_currentNode;
	m_line = i_line;
}	
int ItemData::getComputerName() const
{
	return m_sourceComputer;
}
int  ItemData::getLine() const
{
	return m_line;
}
accessibleListNodeWithPointers*  ItemData::getCurrentNode()const
{
	return m_currentNode;
}
void ItemData::setComputerName(int i_sourceComputer)
{
	m_sourceComputer = i_sourceComputer;
}
void ItemData::setLine(int i_line)
{
	m_line = i_line;
}
void ItemData::setCurrentNode(accessibleListNodeWithPointers* i_newNode)
{
	m_currentNode = i_newNode;

}