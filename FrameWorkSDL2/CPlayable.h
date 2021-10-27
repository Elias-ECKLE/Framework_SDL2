#pragma once
#include "CMovable.h"

enum class controller{oneSide=1, otherSide, idle=0};

class CPlayable: public CMovable {
	Entity ePlayable;
protected:
	controller controlState;
	controller stateTemp;
public:
	//methodes:
	CPlayable();
	~CPlayable();

	controller getControl();
	

	void setControl(controller control);
	void checkX();



};