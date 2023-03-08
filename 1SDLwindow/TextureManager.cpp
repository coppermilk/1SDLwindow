#include "TextureManager.h"

SDL_Texture* TextureManager::pLoadTexture(const char* pFileName)
{
    SDL_Surface* pTempSurface = IMG_Load(pFileName);
    SDL_Texture* pTex = SDL_CreateTextureFromSurface(Game::pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);

    return pTex;
    
}

void TextureManager::DrawMap(SDL_Texture* pTex, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(Game::pRenderer, pTex, &src, &dst);
}
