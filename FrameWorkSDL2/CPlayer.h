#pragma once
#include "CPlayable.h"


class CPlayer : public CPlayable{
	int center;

public:
	CPlayer();
	CPlayer(int x, int y, int w, int h, int speedX, int speedY, std::string str_Name, std::string str_File);
	~CPlayer();


	int getCenter();
	//surchage =
	CPlayer& operator=(const CPlayer& p);

};