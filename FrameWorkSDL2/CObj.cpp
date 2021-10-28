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
	if (this->rect.x<0 || this->rect.x>=eObj.getNb("WINDOW_WIDTH")-eObj.getNb("WIDTH_OBJ")) {
		this->speed.x = this->speed.x*-1;
	}


}

void CObj::checkY()
{
	if (this->rect.y < 0) {
		this->speed.y = this->speed.y * -1;
	}
}

void CObj::directObj(CPlayer& player)
{
	int dist = player.getCenter() - this->rect.x + this->rect.w / 2;
	this->speed.x = this->speed.x+dist*-0.1;
	this->speed.y = this->speed.y * -1;
}



bool CObj::isCollisionPlayer(SDL_Rect playerRect)
{
	return SDL_HasIntersection(&this->rect, &playerRect);
	
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
