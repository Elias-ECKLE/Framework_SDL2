#pragma once
//file to stock data game

#include <map>

#include <iostream>
//#include "CList.h"


using namespace::std;


//_______________________________________________________MAGIC VALUES GAME_________________________________________________


#ifndef Entity_H
#define Entity_H

#define NB_X_BLOCKS_TILESET 13
#define NB_Y_BLOCKS_TILESET 11
#define NB_BLOCKS_TILESET NB_X_BLOCKS_TILESET*NB_Y_BLOCKS_TILESET

#define NB_X_BLOCKS_WIN 40
#define NB_Y_BLOCKS_WIN 21
#define NB_BLOCKS_WIN NB_X_BLOCKS_WIN*NB_Y_BLOCKS_WIN


class Entity {

	//DATA BY DEFAULT ACCORDING THE GAME

	std::map<std::string, int> m_nb_Entities{

		{"WINDOW_WIDTH", 640},
		{"WINDOW_HEIGHT", 340},

		{"TILESET_WIDTH",220},
		{"TILESET_HEIGHT",186},

		{"WIDTH_TILE",16},
		{"HEIGHT_TILE",16},

		{"FPS",60},
		{"MS", 1000},
		







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
		{"NAME_LVL1","Lvl Mario Bros"},
		{"FILE_IMAGE_TILESET","../Images/marioTileset.png"},
		{"FILE_TEXT_TILESET","../Texts/marioTileset.txt"},
	


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




