#pragma once
#include <string>
#include <list>


namespace NextAction {
	typedef std::string string;
	struct weights
	{
		int creative;
		int physical;
		int mental;
		int emotional;
	};
	const struct weights empty = weights{ 0, 0, 0, 0 };

	class action
	{
		typedef std::list<action> TodoList;
		typedef TodoList::iterator iter;
		TodoList* prerequisites;
		string title;
		string desc;
		iter reader;
	protected:
		struct weights energy;
	public:
		action();
		~action();
		action(string title, string desc, int creative, int physical, int mental, int emotional);
		void setEnergy(struct weights totalSoFar);
		void setIter(iter newIterator) { this->reader = newIterator; }
		void setDescription(std::string newDesc) { this->desc = newDesc; }
		void setTitle(string newTitle) { this->title = newTitle; }
		struct weights getEnergy() { return this->energy; }
		int getCreative() { return this->energy.creative; }
		int getPhysical() { return this->energy.physical; }
		int getMental() { return this->energy.mental; }
		int getEmotional() { return this->energy.emotional; }
		iter getFirst() { reader = prerequisites->begin(); return --reader; }
		iter getLast() { reader = prerequisites->end(); return --reader; }
		iter getNext() { return ++reader; }
		iter getPrev() { return --reader; }
		TodoList* getPrereqs() { return prerequisites; }
		string getTitle() { return this->title; }
		string getDesc() { return this->desc; }
	};

}