#pragma once
#include "CMovable.h"

class CObj: public CMovable{

	//here is the ball interactable object
	Entity eObj;

public:
	CObj();
	CObj(int x,  int y, int w, int h, int speedX, int speedY,std::string str_Name, std::string str_File);
	~CObj();


	void checkX();
	void checkY();

	//surchage =
	CObj& operator=(const CObj& p);
};