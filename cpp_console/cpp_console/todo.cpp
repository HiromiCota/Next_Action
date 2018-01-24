#include "todo.h"
#include <ppltasks.h>


todo::todo()
{
	root = nullptr;
	easiest = new superNode();	
}


todo::~todo()
{
	destroyTree();
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
/*
 * Either starts the tree (why would it ever be empty?) or calls the recursive version
 */
void todo::insert(action* node)
{
	if (root != nullptr) //Not the first node; insert left recursively
		insert(node, root);
	else if (node != nullptr) //The first node; just stick it at root
		root = node;
	//If both the node and the root are nullptr, we don't need to do anything
}
/*
 * Recurse until the last node of that level.
 */
void todo::insert(action* node, action* sibling)
{
	if (sibling->getSibling() == nullptr) //No sibling; insert
		sibling->setSibling(node);
	else
		insert(node, sibling->getSibling()); //Sibling exists, traverse left and try again
}
/*
 * Add a prereq. If one already exists, insert this node ahead of it.
 * 
 *  Node can be a tree. This function will handle it 
 */
void todo::addPreReq(action* node, action* parent)
{
	if (parent->getPrereq() != nullptr) { 
		// There is the possibility that node is a tree. If it is, we need to prevent orphaned nodes
		action* endPoint = node;
				
		while (endPoint->getPrereq() != nullptr) // Traverse pre-reqs in the incoming tree until the end
			endPoint = endPoint->getPrereq();

		//End of node tree found. Connecting old prereqs to the back of the new ones.
		endPoint->setPrereq(parent->getPrereq());			
	}
	//Now node can safely be connected to parent.
	parent->setPrereq(node);
	
}
/*
 * Non-recursive part of findEasiestActions()
 * This exists solely to prevent unneccessary checking for nullptrs. 
 * All nodes passed to the overloaded version either exist or the pointers are bad.
 */
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

/*
 * Returns a superNode with the lowest cost actions
 * 
 * Depends on compareSuperNodes()
 */
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
	delete temp; //Take care of your trash
	return easiest; //Note: This isn't deleted because it's the return value, BUT SOMETHING NEEDS TO DELETE IT!
}
/*
 * Determines which nodes have the lowest energy weights and assigns their pointers to best
 */
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
void todo::destroyTree(action* node)
{
	if (node->getSibling() != nullptr)	// Trash all siblings
		destroyTree(node->getSibling());
	if (node->getPrereq() != nullptr)	// Trash all prereqs
		destroyTree(node->getPrereq());
	remove(node);						// Trash this node
}
/*
 * This doesn't check for siblings or children. 
 */
void todo::remove(action* node)
{
	if (node->getParent()->getPrereq() == node) //Then, node is a prereq
		node->getParent()->setPrereq(nullptr);
	else
		node->getParent()->setSibling(nullptr); //Node is a sibling
	delete node;
}


