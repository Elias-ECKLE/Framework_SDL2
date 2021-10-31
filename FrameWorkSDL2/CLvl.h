#pragma once
#include "Component.h"

#ifndef Clvl_H
#define Clvl_H




class CLvl :public Component {


	int nb_Width_Tilset;
	int nb_Height_Tileset;
	int nb_TilesX_Tileset;
	int nb_TilesY_Tileset;
	int nb_Width_Tile;
	int nb_Height_Tile;

	TileProp arrayTiles[NB_BLOCKS_TILESET];
	int nb_TilesX_Win;
	int nb_TilesY_Win;

	std::string str_FileText;
	int arraySchema[NB_X_BLOCKS_WIN][NB_Y_BLOCKS_WIN];


public:

	CLvl();
	CLvl(int,int,int,int,int,int,int,int,std::string,std::string,std::string);
	~CLvl();


	


	//methodes
	void loadMap_Tileset();
	bool loadMap_Lvl(FILE*);
	bool loadMap();
	SDL_Rect getRectDest(int, int);
	SDL_Rect getRectSource(int, int);

	//surchages 
		//surchage =
	CLvl& operator=(const CLvl& lvl);
};



#endif