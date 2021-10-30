#pragma once
#include <iostream>
#include "Component.h"


#ifndef CMovable_H
#define CMovable_H


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

	//if there is movement then possibilities of collision and interactions
	bool isColisionWith(SDL_Rect)const;
	

};

#endif