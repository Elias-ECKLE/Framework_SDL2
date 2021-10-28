#include "CPlayable.h"


CPlayable::CPlayable() {

	this->controlState= controller::oneSide;
	this->stateTemp = controller::idle;
	std::cout << "CPlayable class constructor ok " << std::endl;
}

CPlayable::~CPlayable()
{
	std::cout << "CPlayable class destruction ok " << std::endl;
}

controller CPlayable::getControl()
{
	return this->controlState;
}

void CPlayable::setControl(controller control)
{
	this->stateTemp=this->controlState;
	this->controlState = control;

	checkX();
}

void CPlayable::checkX()
{

	switch (this->controlState) {

		case controller::oneSide:
			if (this->rect.x >= 0 && this->rect.x <= ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER")) {
				this->dpltLessX();

			}
			else if (this->rect.x < 0) {
				this->rect.x = 0;
			}

		break;

		case controller::otherSide:
			if (this->rect.x >= 0 && this->rect.x <= ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER")) {
				this->dpltPlusX();

			}
			else if (rect.x > ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER")) {
				this->rect.x = ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER");

			}

		break;
	}


	
	
}






