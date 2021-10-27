#include "CMovable.h"

CMovable::CMovable()
{
	this->speed.x = 1;
	this->speed.y = this->speed.x;

	std::cout << "CMovable class constructor ok " << std::endl;
}

CMovable::~CMovable()
{
	std::cout << "CMovable class destruction ok " << std::endl;
}

CSpeed<int> CMovable::getSpeed()
{
	return this->speed;
}

void CMovable::dpltPlusX()
{
	this->pos.x += this->speed.x;
}
void CMovable::dpltLessX()
{
	this->pos.x -= this->speed.x;
}

void CMovable::dpltPlusY()
{
	this->pos.y += this->speed.y;
}
void CMovable::dpltLessY()
{
	this->pos.y -= this->speed.y;
}

