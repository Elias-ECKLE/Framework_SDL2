#include "CLvl.h"

CLvl::CLvl()
{
	this->nb_Height_Tileset = 0;
	this->nb_Width_Tilset = 0;
	this->nb_TilesX_Win = 0;
	this->nb_TilesY_Win = 0;
	this->nb_TilesX_Tileset = 0;
	this->nb_TilesY_Tileset = 0;

	this->nb_Width_Tile = 0;
	this->nb_Height_Tile = 0;

	this->rect = { 0,0,0,0 };

	this->str_ComponentName = "";
	this->str_FileName = "";
	this->str_FileText = "";


}

CLvl::CLvl(int nbWidthTilset, int nbHeightTileset, int nbTilesXTileset, int nbTilesYTileset, int nbTilesXWin, int nbTilesYWin, int w, int h, std::string fileImage, std::string CompName, std::string fileText)
{
	this->nb_Height_Tileset = nbHeightTileset;
	this->nb_Width_Tilset = nbWidthTilset;
	this->nb_TilesX_Win = nbTilesXWin;
	this->nb_TilesY_Win = nbTilesYWin;
	this->nb_TilesX_Tileset = nbTilesXTileset;
	this->nb_TilesY_Tileset = nbTilesYTileset;
	this->nb_Width_Tile = w;
	this->nb_Height_Tile = h;



	this->rect.w = w;
	this->rect.h = h;
	this->rect.x = 0;
	this->rect.y = 0;
	this->str_ComponentName = CompName;
	this->str_FileName = fileImage;
	this->str_FileText = fileText;





}

CLvl::~CLvl()
{
}



void CLvl::loadMap_Tileset()
{
	int cpt=0;
	for (int i = 0; i <this->nb_TilesY_Tileset; i++)
	{
		for (int j = 0; j <this->nb_TilesX_Tileset; j++)
		{
			this->arrayTiles[cpt].r.w = this->nb_Width_Tile;
			this->arrayTiles[cpt].r.h = this->nb_Height_Tile;
			this->arrayTiles[cpt].r.x = j * this->arrayTiles[cpt].r.w;
			this->arrayTiles[cpt].r.y = i * this->arrayTiles[cpt].r.h;
			     
			this->arrayTiles[cpt].layerCollision = true;
			if (cpt ==0 )
				this->arrayTiles[cpt].layerCollision = false;

			cpt++;
		}
	}
}

bool CLvl::loadMap_Lvl(FILE* F)
{
	int tmp=0;
	
	for (int i = 0; i < this->nb_TilesY_Win; i++)
	{
		for (int j = 0; j < this->nb_TilesX_Win; j++)
		{
			
			if (tmp>=this->nb_TilesX_Tileset*this->nb_TilesY_Tileset) {
				return false;
			}
			else {
				fscanf_s(F, "%d", &tmp);
				this->arraySchema[j][i] = tmp;
			}
		}
	}
	return true;
}

bool CLvl::loadMap()
{
	FILE* F;
	errno_t err;

	if ((err = fopen_s(&F, this->str_FileText.c_str(), "r")) != 0) {

		std::cout << "Error file text" << std::endl;
		return false;
	}
	loadMap_Tileset();
	loadMap_Lvl(F);

	fclose(F);

	return true;

}

SDL_Rect CLvl::getRectDest(int i, int j)
{
	this->rect.x= j*this->nb_Width_Tile;
	this->rect.y = i*this->nb_Height_Tile;


	return this->rect;

}

SDL_Rect CLvl::getRectSource(int i, int j)
{
	int index = this->arraySchema[j][i];
	return this->arrayTiles[index].r;
}


CLvl& CLvl::operator=(const CLvl& lvl)
{
	this->nb_Height_Tileset = lvl.nb_Height_Tileset;
	this->nb_Width_Tilset = lvl.nb_Width_Tilset;
	this->nb_TilesX_Win = lvl.nb_TilesX_Win;
	this->nb_TilesY_Win = lvl.nb_TilesY_Win;
	this->nb_TilesX_Tileset = lvl.nb_TilesX_Tileset;
	this->nb_TilesY_Tileset = lvl.nb_TilesY_Tileset;

	this->rect = lvl.rect;
	//this->arrayTiles = lvl.arrayTiles;
	this->nb_Width_Tile = lvl.nb_Width_Tile;
	this->nb_Height_Tile = lvl.nb_Height_Tile;

	this->str_ComponentName = lvl.str_ComponentName;
	this->str_FileName = lvl.str_FileName;
	this->str_FileText = lvl.str_FileText;


	return *this;
}
