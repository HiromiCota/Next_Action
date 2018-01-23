#include "action.h"



action::action()
{
	this->setSibling(nullptr);
	this->setPrereq(nullptr);
	this->setParents(nullptr);
	this->setDescription("Default description.");
	this->setTitle("Default Title");
	this->setEnergy(empty);
}
action::action(std::string title, std::string desc, int creative, int physical, int mental, int emotional)
{
	this->setTitle(title);
	this->setDescription(desc);
	this->setEnergy(weights{ creative, physical, mental, emotional });
	this->setSibling(nullptr);
	this->setPrereq(nullptr);
}


action::~action()
{
}

void action::setEnergy(weights totalSoFar)
{
	energy.creative = totalSoFar.creative;
	energy.emotional = totalSoFar.emotional;
	energy.mental = totalSoFar.mental;
	energy.physical = totalSoFar.physical;
}

struct weights action::getEnergy()
{
	if (this->prerequisite != nullptr)
	{
		struct weights temp = this->prerequisite->getEnergy();
		temp.creative += this->energy.creative;
		temp.emotional += this->energy.emotional;
		temp.mental += this->energy.mental;
		temp.physical += this->energy.physical;
		return temp;
	}
	else
		return this->energy;
}

