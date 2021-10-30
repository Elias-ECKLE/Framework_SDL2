#include "CEnemy.h"

CEnemy::CEnemy()
{
}

CEnemy::CEnemy(int x, int y, int w, int h, std::string str_Name, std::string str_File)
{
	this->rect.x = x;
	this->rect.y = y;
	this->rect.w = w;
	this->rect.h = h;
	this->str_ComponentName = str_Name;
	this->str_FileName = str_File;
}

CEnemy::~CEnemy()
{
}

bool CEnemy::isCollisionWith(SDL_Rect rect)
{
	return SDL_HasIntersection(&this->rect, &rect);
}

CEnemy& CEnemy::operator=(const CEnemy& enemy)
{
	this->rect.x = enemy.rect.x;
	this->rect.y =enemy.rect.y;
	this->rect.w = enemy.rect.w;
	this->rect.h = enemy.rect.h;
	this->str_ComponentName = enemy.str_ComponentName;
	this->str_FileName = enemy.str_FileName;

	return *this;
}
