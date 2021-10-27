#pragma once
//file to stock data game

#include <map>

#include <iostream>
//#include "CList.h"


using namespace::std;

//_______________________________________________________MAGIC VALUES GAME_________________________________________________


class Entity {



	//DATA BY DEFAULT ACCORDING THE GAME

	std::map<std::string, int> m_nb_Entities{

		{"WINDOW_WIDTH", 700},
		{"WINDOW_HEIGHT", 720},
		{"FPS",60},
		{"MS", 1000},
		{"COEFF_SCORE", 1},

		{"WIDTH_PLAYER", 98},
		{"HEIGHT_PLAYER", 26},
		{"WIDTH_ENNEMY", 5},
		{"HEIGHT_ENNEMY", 5},
		{"WIDTH_OBJ", 21},
		{"HEIGHT_OBJ",21},

		{"POS_Y_PLAYER",650},
		{"POS_X_ENNEMY",5},
		{"POS_Y_ENNEMY",5},
		{"POS_X_OBJ",500},
		{"POS_Y_OBJ",320},


		{"SPEED_X_OBJ",7},
		{"SPEED_Y_OBJ",4},
		{"SPEED_X_PLAYER",6},
		{"SPEED_Y_PLAYER",4},

		{"TAILLE_POLICE",9},
		{"WIDTH_TEXT",20},
		{"HEIGHT_TEXT",40},
		{"R_COLOR", 255},
		{"G_COLOR", 255},
		{"B_COLOR", 255},
		{"A_OPACITY",255}
	};


	std::map<std::string, std::string>m_str_Entities{


		{"TITLE_SYSTEM","Engine System"},
		{"TITLE_GAME","GAME"},
		{"NAME_ENEMY","Brick"},
		{"NAME_PLAYER","Player"},
		{"NAME_OBJ","Ball"},
		{"FILE_RESSOURCE_PLAYER","../Images/barreJ1.png"},
		{"FILE_RESSOURCE_ENNEMY","./"},
		{"FILE_RESSOURCE_OBJ","../Images/balle.png"}


	};



public :

	//constructeur 
	Entity();

	//destructeur
	~Entity();

	//accesseur :
	int getNb(std::string key);
	std::string getStr(std::string key);

	//methodes :
	
	void addToNbEntity(std::string newKey, int newNb);
	//void addToStrEntity();
	void displayNbEntites();

	





};







