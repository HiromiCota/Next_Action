#include "action.h"


namespace NextAction {
	action::action()
	{
		this->prerequisites = nullptr;
		this->setDescription("Default action description.");
		this->setTitle("Default Next Action");
		this->setEnergy(empty);
		//Note: reader is undefined until prerequisites has something.	
	}
	action::action(string title, string desc, int creative, int physical, int mental, int emotional)
	{
		this->prerequisites = nullptr;
		this->setTitle(title);
		this->setDescription(desc);
		this->setEnergy(weights{ creative, physical, mental, emotional });
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


}