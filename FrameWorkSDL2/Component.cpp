#include "Component.h"

Component::Component()
{
	this->str_ComponentName = "";
	this->str_FileName = "";
	this->rect = { 1,1,1,1 };

	std::cout << "CComponent class constructor ok " << std::endl;
}

Component::~Component()
{
	std::cout << "CComponent class destruction ok " << std::endl;
}

std::string Component::getFileName()const
{
	return this->str_FileName;
}

std::string Component::getCompName() const
{
	return this->str_ComponentName;
}



SDL_Rect Component::getRect()const
{
	return this->rect;
}

void Component::setRectW(int w)
{
	this->rect.w = 0;
}

void Component::setRectH(int h)
{
	this->rect.h = 0;
}



