#include "TextureManager.h"

SDL_Texture* TextureManager::pLoadTexture(const char* pFileName, SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(pFileName);
    SDL_Texture* pTex = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    return pTex;
    
}
