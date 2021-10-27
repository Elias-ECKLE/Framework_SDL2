#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "structs.h"

#include "CRessourcesManager.h"
#include"CGameStateFinished.h"
#include"Entity.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CObj.h"


class System{

	bool b_Running;
	bool b_Win;
	std::string str_pGameName;

	int nb_Fps;
	int nb_Ms;


	CDimensions<int> taille;
	SDL_Window* win_pWindow;
	SDL_Renderer* rend_pRenderer;
	
	CRessourceManager textureManager;
	CPlayer player;
	//CEnemy enemy;
	CObj obj;
	CGameStateFinished GameOver;
	CGameStateFinished GameVictory;



	Entity eGame;


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
	bool get_BRunning();

	//mutateurs :
	void set_BRunning();

	//surchage d'opérateur :
	//CGameManager& operator=(const CGameManager& gameManager);


};