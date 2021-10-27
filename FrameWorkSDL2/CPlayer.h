#pragma once
#include "CPlayable.h"


class CPlayer : public CPlayable{

public:
	CPlayer();
	CPlayer(int x, int y, int w, int h, int speedX, int speedY, std::string str_Name, std::string str_File);
	~CPlayer();


	//surchage =
	CPlayer& operator=(const CPlayer& p);

};