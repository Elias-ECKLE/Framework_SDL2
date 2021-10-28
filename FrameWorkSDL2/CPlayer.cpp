#include "CPlayer.h"



CPlayer::CPlayer()
{
	this->center = this->rect.x+this->rect.w/2;
}

CPlayer::CPlayer(int x, int y,int w,int h, int speedX, int speedY,std::string str_Name, std::string str_File) {

	this->rect.x = x;
	this->rect.y = y;
	
	this->rect.h = h;
	this->rect.w = w;

	this->center = this->rect.x + this->rect.w / 2;

	this->speed.x = speedX;
	this->speed.y = speedY;

	this->str_ComponentName = str_Name;
	this->str_FileName = str_File;

	std::cout << "CPlayer class destruction ok " << std::endl;

}


CPlayer::~CPlayer()
{
	std::cout << "CPlayer class destruction ok " << std::endl;
}

int CPlayer::getCenter()
{
	return this->center;
}

CPlayer& CPlayer::operator=(const CPlayer& p)
{
	this->rect.x = p.rect.x;
	this->rect.y = p.rect.y;

	this->rect.h = p.rect.h;
	this->rect.w = p.rect.w;
	this->center = p.center;

	this->speed.x = p.speed.x;
	this->speed.y = p.speed.y;

	this->str_ComponentName = p.str_ComponentName;
	this->str_FileName = p.str_FileName;

	return *this;
}
