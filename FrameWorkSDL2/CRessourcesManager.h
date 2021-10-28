#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>

#include "Structs.h"

class CRessourceManager {


	std::map<std::string, SDL_Texture*>m_textureMap;

public :

	CRessourceManager();
	~CRessourceManager();

	bool load(std::string str_fileName, std::string str_Key, SDL_Renderer* rend_pRenderer);
	void draw(std::string str_Key, SDL_Rect rectTemp, SDL_Renderer* pRenderer);
	//void drawFrame(std::string str_Key, CCoords<int> pos, CDimensions<int> taille, int nb_CurrentRow, int nb_CurrentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)


};