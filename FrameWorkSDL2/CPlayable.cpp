#include "CPlayable.h"


CPlayable::CPlayable() {

	this->controlState= controller::oneSide;
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
			if (this->pos.x <= ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER")) {
				this->dpltLessX();

			}
			else if (this->pos.x < 0) {
				this->pos.x = 0;
			}
			else if (pos.x > ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER")) {
				this->pos.x = ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER");

			}
		break;

		case controller::otherSide:
			if (this->pos.x >= 0 && this->pos.x <= ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER")) {
				this->dpltPlusX();

			}
			else if (this->pos.x < 0) {
				this->pos.x = 0;
			}
			else if (pos.x > ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER")) {
				this->pos.x = ePlayable.getNb("WINDOW_WIDTH") - ePlayable.getNb("WIDTH_PLAYER");

			}

		break;
	}


	
	
}






