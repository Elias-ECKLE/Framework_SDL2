#pragma once

//Components class to create object interacting with other in game

#include <SDL.h>
#include <iostream>
#include "Structs.h"

class Component {

protected :
	std::string str_FileName;
	std::string str_ComponentName;
	CCoords<int> pos;
	CDimensions<int> taille;

public:
	Component();
	~Component();


	std::string getFileName();
	std::string getCompName();
	CCoords<int> getPos();
	CDimensions<int> getTaille();


};