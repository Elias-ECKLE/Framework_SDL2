#pragma once
#include "CMovable.h"

#ifndef CPlayable_H
#define CPlayable_H

enum class controller{oneSide=1, otherSide, idle=0};

class CPlayable: public CMovable {
	Entity datas;

protected:
	controller controlState;
	controller stateTemp;
public:
	//methodes:
	CPlayable();
	~CPlayable();

	controller getControl()const;
	

	void setControl(controller control);
	void checkX();



};

#endif