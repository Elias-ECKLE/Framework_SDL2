#include "CPlayable.h"


CPlayable::CPlayable() {

	this->controlState= controller::oneSide;
	std::cout << "CPlayable class constructor ok " << std::endl;
}

CPlayable::~CPlayable()
{
	std::cout << "CPlayable class destruction ok " << std::endl;
}

controller CPlayable::getControl()const
{
	return this->controlState;
}

void CPlayable::setControl(controller control)
{
	this->controlState = control;

}

void CPlayable::checkX()
{


	
	
}






