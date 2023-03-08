#pragma once
#include "Game.h"

class TextureManager
{
public: 
	static SDL_Texture* pLoadTexture(const char * pFileName, SDL_Renderer * pRenderer);
};

