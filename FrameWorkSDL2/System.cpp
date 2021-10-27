#include "System.h"


System::System()
{
	this->b_Running = false;
	this->str_pGameName =eGame.getStr("TITLE_GAME");


	this->taille.w = eGame.getNb("WINDOW_WIDTH");
	this->taille.h = eGame.getNb("WINDOW_HEIGHT");

	this->b_Win = false;
	this->nb_Fps = eGame.getNb("FPS");
	this->nb_Ms = eGame.getNb("MS");

	this->win_pWindow = nullptr;
	this->rend_pRenderer = nullptr;


	CPlayer playerTemp(
		eGame.getNb("WINDOW_WIDTH")/2 - eGame.getNb("WIDTH_PLAYER")/2,
		eGame.getNb("POS_Y_PLAYER"),
		eGame.getNb("WIDTH_PLAYER"), 
		eGame.getNb("HEIGHT_PLAYER"), 
		eGame.getNb("SPEED_X_PLAYER"), 
		eGame.getNb("SPEED_Y_PLAYER"), 
		eGame.getStr("NAME_PLAYER"), 
		eGame.getStr("FILE_RESSOURCE_PLAYER")
	);
	player=playerTemp;

	CObj objTemp(
		eGame.getNb("WINDOW_WIDTH") / 2 - eGame.getNb("WIDTH_OBJ") / 2, 
		eGame.getNb("WINDOW_HEIGHT")*0.75 - eGame.getNb("HEIGHT_OBJ") / 2,
		eGame.getNb("WIDTH_OBJ"),
		eGame.getNb("HEIGHT_OBJ"),
		eGame.getNb("SPEED_X_OBJ"),
		eGame.getNb("SPEED_Y_OBJ"),
		eGame.getStr("NAME_OBJ"),
		eGame.getStr("FILE_RESSOURCE_OBJ")
	);
	obj = objTemp;

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
	textureManager.load(this->player.getFileName(), this->player.getCompName(), this->rend_pRenderer);
	//textureManager.load(eGame.getStr("FILE_RESSOURCE_ENEMY)"), eGame.getStr("NAME_ENEMY"), this->rend_pRenderer);
	textureManager.load(this->obj.getFileName(),this->obj.getCompName(), this->rend_pRenderer);

	this->b_Running = true;


	

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
			case SDL_KEYDOWN:

				switch (event.key.keysym.sym) {
					case SDLK_LEFT:
						this->player.setControl(controller::oneSide);
					break;
					case SDLK_RIGHT:
						this->player.setControl(controller::otherSide);
					break;
				}
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

	//draw images and objects :
	textureManager.draw(this->player.getCompName(),this->player.getPos(),this->player.getTaille(),this->rend_pRenderer);
	textureManager.draw(this->obj.getCompName(), this->obj.getPos(), this->obj.getTaille(), this->rend_pRenderer);

	SDL_RenderPresent(this->rend_pRenderer);
	SDL_Delay(this->nb_Ms/nb_Fps);
}

void System::clean()
{
	SDL_DestroyWindow(this->win_pWindow);
	SDL_DestroyRenderer(this->rend_pRenderer);
}

bool System::get_BRunning()
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