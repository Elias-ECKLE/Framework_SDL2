#include "CObj.h"

CObj::CObj()
{
}

CObj::CObj(int x, int y, int w, int h, int speedX, int speedY, std::string str_Name, std::string str_File)
{
	this->rect.x = x;
	this->rect.y = y;

	this->rect.h = h;
	this->rect.w = w;

	this->speed.x = speedX;
	this->speed.y = speedY;

	this->str_ComponentName = str_Name;
	this->str_FileName = str_File;
}

CObj::~CObj()
{
	std::cout << "CObj class destruction ok " << std::endl;
}

void CObj::checkX()
{
	


}

void CObj::checkY()
{
	
	
}

void CObj::inversX()
{
	this->speed.x *= -1;
}

void CObj::inversY()
{
	this->speed.y *= -1;
}

void CObj::directObj(CPlayer& player)
{
}





CObj& CObj::operator=(const CObj& p)
{
	this->rect.x = p.rect.x;
	this->rect.y = p.rect.y;

	this->rect.h = p.rect.h;
	this->rect.w = p.rect.w;

	this->speed.x = p.speed.x;
	this->speed.y = p.speed.y;

	this->str_ComponentName = p.str_ComponentName;
	this->str_FileName = p.str_FileName;
	
	return *this;
}
