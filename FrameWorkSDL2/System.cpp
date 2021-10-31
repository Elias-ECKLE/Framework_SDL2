#include "System.h"


System::System()
{
	this->b_Running = false;
	this->str_pGameName =datas.getStr("TITLE_GAME");


	this->taille.w = datas.getNb("WINDOW_WIDTH");
	this->taille.h = datas.getNb("WINDOW_HEIGHT");

	this->b_Win = false;
	this->b_Start = true;
	this->nb_Fps = datas.getNb("FPS");
	this->nb_Ms = datas.getNb("MS");

	this->win_pWindow = nullptr;
	this->rend_pRenderer = nullptr;


	CLvl lvlTemp(
		this->datas.getNb("TILESET_WIDTH"),
		this->datas.getNb("TILESET_HEIGHT"),
		NB_X_BLOCKS_TILESET,
		NB_Y_BLOCKS_TILESET,
		NB_X_BLOCKS_WIN,
		NB_Y_BLOCKS_WIN,
		this->datas.getNb("WIDTH_TILE"),
		this->datas.getNb("HEIGHT_TILE"),
		this->datas.getStr("FILE_IMAGE_TILESET"),
		this->datas.getStr("NAME_LVL1"),
		this->datas.getStr("FILE_TEXT_TILESET")
	);

	this->lvl1 = lvlTemp;

}
/*
System::System(std::string str_Name, int nb_fps, int nb_ms, int w, int h)
{
	this->str_pGameName = str_Name ;
	this->nb_Fps = nb_fps;
	this->nb_Ms = nb_ms;
	this->taille.w = w;
	this->taille.h = h;
}

System::System(const System& gameTemp)
{
	this->b_Running = gameTemp.b_Running;
	this->str_pGameName = gameTemp.str_pGameName;


	this->taille.w = gameTemp.taille.w;
	this->taille.h = gameTemp.taille.h;

	this->b_Win = gameTemp.b_Win;
	this->nb_Fps = gameTemp.nb_Fps;
	this->nb_Ms = gameTemp.nb_Ms;


	this->win_pWindow = gameTemp.win_pWindow;
	this->rend_pRenderer = gameTemp.rend_pRenderer;
}
*/
System::~System()
{
	std::cout << "System class destruction ok" << std::endl;
}

bool System::init() {

	//init the SDLs librairies
	this->initSDL();
	this->initSDL_IMG();
	this->initSDL_TEXT();





	
	//load textures
	this->textureManager.load(this->lvl1.getFileName(), this->lvl1.getCompName(), this->rend_pRenderer);
	this->lvl1.loadMap();




	//tab of ennemis :


	return true;
}

bool System::initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING)==0) {
		std::cout << "Init SDL successful !" << std::endl;

		this->win_pWindow = SDL_CreateWindow(this->str_pGameName.c_str(), SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			this->taille.w,
			this->taille.h,
			SDL_WINDOW_SHOWN);

		if (this->win_pWindow) {
			std::cout << "creation window successful !" << std::endl;

			this->rend_pRenderer = SDL_CreateRenderer(this->win_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);

			if (this->rend_pRenderer) {
				std::cout << "creation renderer successful !" << std::endl;
				SDL_SetRenderDrawColor(this->rend_pRenderer,
					0, 0, 0, SDL_ALPHA_OPAQUE);
			}
			else {
				std::cout << "echec creation renderer" << std::endl;
				return false;
			}
		}
		else {
			std::cout << "error creation window" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "echec init SDL2" << std::endl;
		return false;
	}

	//start the game loop when initialisation finished
	this->b_Running = true;
	return true;
}

bool System::initSDL_IMG()
{
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted & flags) != flags) {
		SDL_Log("IMG_Init:Failed to init required jpg and png support !\n");
		SDL_Log("IMG_Init: %s\n", IMG_GetError());
		return false;
	}

	return true;
}

bool System::initSDL_TEXT()
{
	if (TTF_Init() == -1) {
		SDL_Log("TEXT_Init:Failed to init ttf!\n");
		return false;
	}
	return true;
}




void System::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				this->b_Running = false;
			break;

			default:
			break;
		}
	}
}

void System::update()
{
	


	
}

void System::render()
{
	SDL_RenderClear(this->rend_pRenderer);


	//draw lvl :
	SDL_Rect rectDest;
	for (int i=0; i <NB_Y_BLOCKS_WIN ;i++) {
		for (int j=0; j <NB_X_BLOCKS_WIN ; j++) {

			this->textureManager.draw(this->lvl1.getCompName(), this->lvl1.getRectSource(i, j), this->lvl1.getRectDest(i,j), this->rend_pRenderer);
		}
	}


	SDL_RenderPresent(this->rend_pRenderer);
	SDL_Delay(this->nb_Ms/nb_Fps);
}

void System::clean()
{
	SDL_DestroyWindow(this->win_pWindow);
	SDL_DestroyRenderer(this->rend_pRenderer);
}

bool System::get_BRunning()const
{
	return this->b_Running;
}

void System::set_BRunning()
{
}
/*
System& System::operator=(const System& gameManager)
{
	this->b_Running = gameManager.b_Running;
	this->str_pGameName = gameManager.str_pGameName;


	this->taille.w = gameManager.taille.w;
	this->taille.h = gameManager.taille.h;

	this->b_Win = gameManager.b_Win;
	this->nb_Fps = gameManager.nb_Fps;
	this->nb_Ms = gameManager.nb_Ms;

	
	this->win_pWindow = gameManager.win_pWindow;
	this->rend_pRenderer = gameManager.rend_pRenderer;

	return *this;
}
*/