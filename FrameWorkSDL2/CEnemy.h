#pragma once
#include "Component.h"

#ifndef CEnemy_H
#define CEnemy_H

class CEnemy : public Component{

public :
	CEnemy();
	CEnemy(int x, int y, int w, int h, std::string str_Name, std::string str_File);
	~CEnemy();

	//surchages:
	bool isCollisionWith(SDL_Rect rect);
	CEnemy& operator=(const CEnemy& enemy);

};

#endif