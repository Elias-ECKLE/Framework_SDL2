#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <string>

#ifndef CLvlManager_H
#define ClvlManager_H

class CLvlManager {

public :
	CLvlManager();
	~CLvlManager();


	//methodes :
	SDL_Surface* loadImage(std::string);
};

#endif