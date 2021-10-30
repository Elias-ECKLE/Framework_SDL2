#pragma once
#include "CPlayable.h"


#ifndef CPlayer_H
#define CPlayer_H

class CPlayer : public CPlayable{
	int center;

public:
	CPlayer();
	CPlayer(int x, int y, int w, int h, int speedX, int speedY, std::string str_Name, std::string str_File);
	~CPlayer();


	int getCenter()const;
	//surchage =
	CPlayer& operator=(const CPlayer& p);

};

#endif