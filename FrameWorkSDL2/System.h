#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "structs.h"
#include<iostream>
#include<string>

#include "CRessourcesManager.h"
#include "CLvl.h"
#include"CGameStateManager.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CObj.h"

#ifndef System_H
#define System_H

class System{

	bool b_Running;
	bool b_Start;
	bool b_Win;
	std::string str_pGameName;

	int nb_Fps;
	int nb_Ms;


	CDimensions<int> taille;
	SDL_Window* win_pWindow;
	SDL_Renderer* rend_pRenderer;
	
	CRessourceManager textureManager;
	CLvl lvl1;

	CGameStateManager GameOver;
	CGameStateManager GameVictory;



	Entity datas;


public:
	
	System();
	//CGameManager(std::string, int, int, int, int);
	//CGameManager(const CGameManager& gameTemp);
	~System();

	bool init();
	bool initSDL();
	bool initSDL_IMG();
	bool initSDL_TEXT();
	

	void handleEvents();
	void update();
	void render();
	void clean();


	//accesseurs :
	bool get_BRunning()const;

	//mutateurs :
	void set_BRunning();

	//surchage d'opérateur :
	//CGameManager& operator=(const CGameManager& gameManager);


};

#endif