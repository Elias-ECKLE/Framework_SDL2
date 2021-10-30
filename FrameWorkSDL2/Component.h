#pragma once

//Components class to create object interacting with other in game

#include <SDL.h>
#include <iostream>
#include "Structs.h"
#include "Entity.h"





class Component {

protected :
	std::string str_FileName;
	std::string str_ComponentName;
	SDL_Rect rect;

public:
	Component();
	~Component();


	std::string getFileName()const;
	std::string getCompName()const;
	SDL_Rect getRect()const;

	void setRectW(int w);
	void setRectH(int h);




};

