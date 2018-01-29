#include "todo.h"
#include <ppltasks.h>

namespace NextAction {
	todo::todo()
	{
		theseActions = new TodoList();
		easiest = new superNode();
	}


	todo::~todo()
	{
		removePrereqs();
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
		//No longer functional because of the new datastructure
	}
	/*
	 * Recurse until the last node of that level.
	 */
	void todo::insert(action* node, action* sibling)
	{
		//No longer functional because of the new datastructure
	}
	/*
	 * Add a prereq. If one already exists, insert this node ahead of it.
	 *
	 *  Node can be a tree. This function will handle it
	 */
	void todo::addPreReq(action* node, action* parent)
	{
		//No longer functional because of the new datastructure

	}
	/*
	 * Non-recursive part of findEasiestActions()
	 * This exists solely to prevent unneccessary checking for nullptrs.
	 * All nodes passed to the overloaded version either exist or the pointers are bad.
	 */
	todo::superNode* todo::findEasiestActions()
	{
		//No longer functional because of the new datastructure
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

		//This is no longer functional because of the datastructure revision

		easiest->setAll(node);

		// Traverse the whole tree, looking for values. If the values are better than the easiest, copy.

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
	/*
	 * No parameter version defined in .h
	 */
	void todo::removePrereqs(TodoList* prereqs)
	{
		// Traverse list, trash actions
		for (int i =0; i < prereqs->size();i++)
		{
			iter firstNode = prereqs->begin();
			removePrereqs(firstNode->getPrereqs()); //Recurse through all possible prereqs of this node.
			prereqs->erase(firstNode);
		}
		//Now, trash this list
		delete prereqs;
	}
	/*
	 * This doesn't check for siblings or children.
	 */
	void todo::remove(action* node)
	{
		//Find node in TodoList, then blow it away.
	}
	/* Serialization schema
	 * int string string int int int int \n
	 * int: Depth of this node. 0 means it belongs to the root todo. Anything else means it belongs to the first node above it with a lower number
	 * string: Title
	 * string: Desc
	 * int: Creative
	 * int: Physical
	 * int: Mental
	 * int: Emotional
	 * 
	 * e.g. 
	 * 0 "Thing 1" "Do the thing" 0 0 0 2
	 * 1 "Thing 2" "Do this, too" 2 0 2 0
	 * 1 "Thing 3" "Do it" 9 9 9 8
	 * 2 "Thing 4" "Gogogo" 4 4 3 2
	 * 
	 * Thing 4 is a child of Thing 3.
	 * Things 2 and 3 and childs of Thing 1.
	 * Thing 1 is the root list.
	 */
	void todo::saveList()
	{
		// Get file name

		// Validate name

		// Traverse and write

		
	}
	void todo::loadList()
	{
		// Get file name

		// Validate file

		// Traverse and build

		// Does the int at the beginning of the line match the previous line?
		// If yes, then this goes into the same list that the previous node did
		// If no, then this goes into the list IN the previous node.
		// DON'T FORGET TO MAKE A NEW LIST; action's constructor defaults to nullptr for TodoList objects

	}

}