#pragma once
//file to stock data game

#include <map>

#include <iostream>
//#include "CList.h"


using namespace::std;


//_______________________________________________________MAGIC VALUES GAME_________________________________________________

#define NB_ENEMY_LIGN 12
#define NB_COLON 13
#define NB_ENEMY NB_ENEMY_LIGN*NB_COLON

#ifndef Entity_H
#define Entity_H

class Entity {

	//DATA BY DEFAULT ACCORDING THE GAME

	std::map<std::string, int> m_nb_Entities{

		{"WINDOW_WIDTH", 700},
		{"WINDOW_HEIGHT", 720},
		{"FPS",60},
		{"MS", 1000},
		{"COEFF_SCORE", 1},

		{"WIDTH_PLAYER", 147},
		{"HEIGHT_PLAYER", 39},
		{"WIDTH_ENEMY", 48},
		{"HEIGHT_ENEMY", 26},
		{"WIDTH_OBJ", 15},
		{"HEIGHT_OBJ",15},

		{"POS_Y_PLAYER",650},
		{"POS_X_OBJ",500},
		{"POS_Y_OBJ",320},



		{"SPEED_X_OBJ",4},
		{"SPEED_Y_OBJ",4},
		{"SPEED_X_PLAYER",18},
		{"SPEED_Y_PLAYER",18},

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
		{"FILE_RESSOURCE_ENEMY","../Images/brick.png"},
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

//___________________________________________WE INSTANCE A ENTITY FOR TRANSFER DATA IN THE CORRESPOND CLASSES_______________________________



#endif




