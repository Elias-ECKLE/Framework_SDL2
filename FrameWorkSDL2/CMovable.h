#pragma once
#include <iostream>
#include "Component.h"
#include "Entity.h"




class CMovable : public Component {


protected:
	CSpeed<int> speed;

public:
	CMovable();
	~CMovable();

	CSpeed<int> getSpeed();

	//methodes to move component

	void dpltLessX();
	void dpltPlusX();
	void dpltLessY();
	void dpltPlusY();
	

};