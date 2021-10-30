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


	CPlayer playerTemp(
		datas.getNb("WINDOW_WIDTH")/2 - datas.getNb("WIDTH_PLAYER")/2,
		datas.getNb("POS_Y_PLAYER"),
		datas.getNb("WIDTH_PLAYER"), 
		datas.getNb("HEIGHT_PLAYER"), 
		datas.getNb("SPEED_X_PLAYER"), 
		datas.getNb("SPEED_Y_PLAYER"), 
		datas.getStr("NAME_PLAYER"), 
		datas.getStr("FILE_RESSOURCE_PLAYER")
	);
	this->player=playerTemp;

	CObj objTemp(
		datas.getNb("WINDOW_WIDTH") / 2 - datas.getNb("WIDTH_OBJ") / 2, 
		datas.getNb("WINDOW_HEIGHT")*0.75 - datas.getNb("HEIGHT_OBJ") / 2,
		datas.getNb("WIDTH_OBJ"),
		datas.getNb("HEIGHT_OBJ"),
		datas.getNb("SPEED_X_OBJ"),
		datas.getNb("SPEED_Y_OBJ"),
		datas.getStr("NAME_OBJ"),
		datas.getStr("FILE_RESSOURCE_OBJ")
	);
	this->obj = objTemp;



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
	//textureManager.load(datas.getStr("FILE_RESSOURCE_ENEMY)"), datas.getStr("NAME_ENEMY"), this->rend_pRenderer);
	textureManager.load(this->obj.getFileName(),this->obj.getCompName(), this->rend_pRenderer);


	//tab of ennemis :


	int xDecal = datas.getNb("WINDOW_WIDTH") * 0.10;
	int yDecal = datas.getNb("WINDOW_HEIGHT") * 0.05;
	int cpt = 0;

	for (int i = 0; i < NB_COLON; i++) {
		for (int j = 0; j < NB_ENEMY_LIGN; j++) {

			CEnemy enemyTemp(
				xDecal,
				yDecal,
				datas.getNb("WIDTH_ENEMY"),
				datas.getNb("HEIGHT_ENEMY"),
				datas.getStr("NAME_ENEMY")+ std::to_string(cpt),
				datas.getStr("FILE_RESSOURCE_ENEMY")
			);
			this->arrayEnnemy[cpt] = enemyTemp;
			textureManager.load(arrayEnnemy[cpt].getFileName(), arrayEnnemy[cpt].getCompName(), this->rend_pRenderer);

			cpt++;
			xDecal += datas.getNb("WIDTH_ENEMY");
		}
		xDecal = datas.getNb("WINDOW_WIDTH") * 0.10;
		yDecal += datas.getNb("HEIGHT_ENEMY");

	}

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
	//OBJECT DEPLACEMENT__________________________________________________________
	//stop init mov ball and change in function emplacement
	if (this->obj.isColisionWith(this->player.getRect())) {
		this->b_Start = false;
	}
	//when game begins, move ball to the player 
	if (b_Start==true) {
		this->obj.dpltPlusY();
	}
	else {
		//if collision with player then we put the right direction of movement in fucntion place hit
		if (this->obj.isColisionWith(this->player.getRect())) {
			this->obj.directObj(this->player);
		}
		else { //check limits of the window 
			this->obj.checkX();
			this->obj.checkY();
		}
		//move object
		this->obj.dpltPlusX();
		this->obj.dpltPlusY();
	}

	//BRICK COLLISION_____________________________________________________________
	for (int i = 0; i < NB_ENEMY; i++) {

		if (this->arrayEnnemy[i].isCollisionWith(this->obj.getRect())) {
			this->arrayEnnemy[i].setRectW(0);
			this->arrayEnnemy[i].setRectH(0);

			this->obj.inversY(); //if colision then invers direction
		}
	}





	
}

void System::render()
{
	SDL_RenderClear(this->rend_pRenderer);

	//draw images and objects :
	textureManager.draw(this->player.getCompName(),this->player.getRect(),this->rend_pRenderer);
	textureManager.draw(this->obj.getCompName(), this->obj.getRect(), this->rend_pRenderer);
	for (int i = 0; i < NB_ENEMY; i++) {
		textureManager.draw(this->arrayEnnemy[i].getCompName(), this->arrayEnnemy[i].getRect(), this->rend_pRenderer);
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