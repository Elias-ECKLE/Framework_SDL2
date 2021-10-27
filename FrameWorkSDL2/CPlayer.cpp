#include "CPlayer.h"



CPlayer::CPlayer()
{
}

CPlayer::CPlayer(int x, int y,int w,int h, int speedX, int speedY,std::string str_Name, std::string str_File) {

	this->pos.x = x;
	this->pos.y = y;

	this->taille.h = h;
	this->taille.w = w;

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

CPlayer& CPlayer::operator=(const CPlayer& p)
{
	this->pos.x = p.pos.x;
	this->pos.y = p.pos.y;

	this->taille.h = p.taille.h;
	this->taille.w = p.taille.w;

	this->speed.x = p.speed.x;
	this->speed.y = p.speed.y;

	this->str_ComponentName = p.str_ComponentName;
	this->str_FileName = p.str_FileName;

	return *this;
}
