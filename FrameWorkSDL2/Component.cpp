#include "Component.h"

Component::Component()
{
	this->str_ComponentName = "";
	this->str_FileName = "";
	this->pos.x = 1;
	this->pos.y = 1;
	this->taille.w = 1;
	this->taille.h = 1;

	std::cout << "CComponent class constructor ok " << std::endl;
}

Component::~Component()
{
	std::cout << "CComponent class destruction ok " << std::endl;
}

std::string Component::getFileName()
{
	return this->str_FileName;
}

std::string Component::getCompName()
{
	return this->str_ComponentName;
}

CCoords<int> Component::getPos()
{
	return this->pos;
}

CDimensions<int> Component::getTaille()
{
	return this->taille;
}
