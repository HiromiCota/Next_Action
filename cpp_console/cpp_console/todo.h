#pragma once
#include <string>
#include "action.h"
#define DEFAULT_NUMBER_OF_TASKS = 10;

/* The todo class creates a binary action tree.
 * All right branches/leaves are prerequisite tasks of the task they link from.
 * All left brancches/leaves are independent of the task they link from.
 * 
 * Thus, any action with a nullptr prerequisite is an action that is available to be completed.
 * Any actions with a prerequisite cannot be completed.
 * 
 * e.g.
 * root
 * |
 * "Get a job" -- "Prepare code sample" -- "Debug" -- "Write functions" -- "Name functions" -- "Sketch data structures"
 *					|
 *				  "Tailor resume"
 * "Get a job" has the prerequisites of "Prepare code sample" and "Tailor resume"
 * "Tailor resume" can be completed without doing anything else.
 * "Debug" requires that everything to its right be completed first.
 * 
 * creative, physical, emotional, and mental are weights attached to each action, depending on how much of which kind of effort they'll take to complete.
 * This way, it is possible to select the action that best suits the kind of mood the user is in, as well as determine which projects will be
 * the easiest or hardest for the user.
 */


namespace NextAction {
	typedef std::list<action> TodoList;
	typedef TodoList::iterator iter;
	class todo
	{
		class superNode
		{
			action* creativePtr;
			action* emotionalPtr;
			action* physicalPtr;
			action* mentalPtr;

		public:
			superNode();
			~superNode();
			int getCreative() { return this->creativePtr->getCreative(); }
			int getEmotional() { return this->emotionalPtr->getEmotional(); }
			int getPhysical() { return this->physicalPtr->getPhysical(); }
			int getMental() { return this->mentalPtr->getMental(); }
			action* getCreativePtr() { return this->creativePtr; }
			action* getEmotionalPtr() { return this->emotionalPtr; }
			action* getPhysicalPtr() { return this->physicalPtr; }
			action* getMentalPtr() { return this->mentalPtr; }
			void setNode(action* node, action* position) { if (node != nullptr) position = node; }
			void setCreative(action* node) { setNode(node, this->creativePtr); }
			void setEmotional(action* node) { setNode(node, this->emotionalPtr); }
			void setPhysical(action* node) { setNode(node, this->physicalPtr); }
			void setMental(action* node) { setNode(node, this->mentalPtr); }
			void setAll(action* node) { setCreative(node); setEmotional(node); setMental(node); setPhysical(node); }
		};
	public:
		todo();
		~todo();
		void insert(action* node);
		void addPreReq(action* node, action* parent);

		action* search(std::string title);
		struct weights getEnergy(action *node);
		void printEnergy(action *node);
		// Note: file I/O not available this version. Check back tomorrow
		void saveList();
		void loadList();
		void removePrereqs() { removePrereqs(theseActions); }
		TodoList* getRoot() const { return this->theseActions; }
		superNode* findEasiestActions();
		void compareSuperNodes(superNode* best, superNode* temp);
		// Note: None of these actually triggers findEasiestActions. Run it first, or get garbage data
		action* findLowEmotional() { return this->easiest->getEmotionalPtr(); }
		action* findLowCreative() { return this->easiest->getCreativePtr(); }
		action* findLowPhysical() { return this->easiest->getPhysicalPtr(); }
		action* findLowMental() { return this->easiest->getMentalPtr(); }

	private:
		void remove(action *node);
		void insert(action* node, action* sibling);
		void removePrereqs(TodoList* node);
		superNode* findEasiestActions(action* node);

		TodoList* theseActions;
		superNode* easiest;
	};

}