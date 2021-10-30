#pragma once
#include "CMovable.h"
#include "CPlayer.h"


#ifndef CObj_H
#define CObj_H


class CObj: public CMovable{

	//here is the ball interactable object
	Entity datas;

public:
	CObj();
	CObj(int x, int y, int w, int h, int speedX, int speedY,std::string str_Name, std::string str_File);
	~CObj();


	void checkX();
	void checkY(); 
	void inversX();
	void inversY();
	void directObj(CPlayer&);

	//surchage =
	CObj& operator=(const CObj& p);
};

#endif