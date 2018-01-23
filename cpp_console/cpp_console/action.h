#pragma once
#include <string>

struct weights
{
	int creative;
	int physical;
	int mental;
	int emotional;
};
const struct weights empty = weights { 0, 0, 0, 0 };

class action
{
	action* parent;
	action* sibling;
	action* prerequisite;
	std::string title;
	std::string desc;
protected:
	struct weights energy;
public:
	action();
	~action();
	action(std::string title, std::string desc, int creative, int physical, int mental, int emotional);
	struct weights getEnergy();
	void setEnergy(struct weights totalSoFar);
	void setDescription(std::string newDesc){		this->desc = newDesc;	}
	void setTitle(std::string newTitle)		{		this->title = newTitle;	}
	int getCreative() { return this->energy.creative; }
	int getPhysical() { return this->energy.physical; }
	int getMental()   { return this->energy.mental; }
	int getEmotional(){ return this->energy.emotional; }
	action* getSibling() { return this->sibling; }
	action* getPrereq() { return this->prerequisite; }
	action* getParent() { return this->parent; }
	void setSibling(action* node) { this->sibling = node; }
	void setPrereq(action* node) { this->prerequisite = node; }
	void setParents(action* node) { this->parent = node; }
	std::string getTitle() { return this->title; }
	std::string getDesc() { return this->desc; }
};

