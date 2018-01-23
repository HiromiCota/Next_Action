#include "todo.h"
#include <ppltasks.h>


todo::todo()
{
	root = nullptr;
	easiest = new superNode();	
}


todo::~todo()
{
}

todo::superNode::superNode()
{
	setCreative(nullptr);
	setEmotional(nullptr);
	setPhysical(nullptr);
	setMental(nullptr);
}


todo::superNode::~superNode()
{
	
}

void todo::insert(action* node)
{
	if (root != nullptr) //Not the first node; insert left recursively
		insert(node, root);
	else if (node != nullptr) //The first node; just stick it at root
		root = node;
	//If both the node and the root are nullptr, we don't need to do anything
}

void todo::insert(action* node, action* parent)
{
	if (parent->getSibling() == nullptr) //No sibling; insert
		parent->setSibling(node);
	else
		insert(node, parent->getSibling()); //Sibling exists, traverse left and try again
}
todo::superNode* todo::findEasiestActions()
{
	if (root == nullptr) // Ask for bad data, get bad data.
		return nullptr;
	if (root->getSibling() == nullptr && root->getPrereq() == nullptr) // Tree is empty. Root is the only possible node.
	{
		superNode* empty;
		empty = new superNode();
		empty->setAll(root);
		return empty;
	}
	return findEasiestActions(root); //There are at least two nodes. Start evaluating.
}

todo::superNode* todo::findEasiestActions(action* node)
{
	superNode* easiest;
	easiest = new superNode();
	superNode* temp;
	temp = new superNode();
	
	easiest->setAll(node);
	
	// Traverse the whole tree, looking for values. If the values are better than the easiest, copy.
	if (node->getSibling() == nullptr && node->getPrereq() == nullptr) // This is a leaf, therefore nothing below is better. Go back up.
		return easiest;
	if (node->getSibling() != nullptr) //Traverse left
		temp = findEasiestActions(node->getSibling()); 
	compareSuperNodes(easiest, temp); //Store best values
	if (node->getPrereq() != nullptr) //Traverse right
		temp = findEasiestActions(node->getPrereq());
	compareSuperNodes(easiest, temp); //Store best values
	return easiest;
}
void todo::compareSuperNodes(superNode* best, superNode* temp)
{
	if (temp->getCreative() < best->getCreative())
		best->setCreative(temp->getCreativePtr());
	if (temp->getEmotional() < best->getEmotional())
		best->setEmotional(temp->getEmotionalPtr());
	if (temp->getMental() < best->getMental())
		best->setMental(temp->getMentalPtr());
	if (temp->getPhysical() < best->getPhysical())
		best->setPhysical(temp->getPhysicalPtr());
}


