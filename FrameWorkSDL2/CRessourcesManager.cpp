#include "CRessourcesManager.h"

CRessourceManager::CRessourceManager()
{
	std::cout << "CRessourceManager constructor ok" << std::endl;
}

CRessourceManager::~CRessourceManager()
{
	std::cout << "CRessourceManager destruction ok" << std::endl;
}

bool CRessourceManager::load(std::string str_fileName, std::string str_Key, SDL_Renderer* rend_pRenderer)
{
	SDL_Surface* surf_pTempSurface = IMG_Load(str_fileName.c_str()); //conversion in const char*

	if (surf_pTempSurface==nullptr) {
		std::cout << "Echec load IMG SDL_Surface : " << str_Key <<std::endl;
		return false;
	}
	
	SDL_Texture* tex_pTexture = SDL_CreateTextureFromSurface(rend_pRenderer, surf_pTempSurface);
	SDL_FreeSurface(surf_pTempSurface);
	if (tex_pTexture==nullptr) {
		std::cout << "Echec creation texture from surface : " << str_fileName << std::endl;
		return false;
	}

    this->m_textureMap[str_Key] = tex_pTexture;
	return true;
}

void CRessourceManager::draw(std::string str_Key,SDL_Rect rectDest, SDL_Renderer* pRenderer)
 {


	SDL_RenderCopy(pRenderer, m_textureMap[str_Key], NULL, &rectDest);
}

void CRessourceManager::draw(std::string str_Key, SDL_Rect rectSource,SDL_Rect rectDest, SDL_Renderer* pRenderer)
{


	SDL_RenderCopy(pRenderer, m_textureMap[str_Key], &rectSource, &rectDest);
}