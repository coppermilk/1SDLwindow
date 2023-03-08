#pragma once
#include "Game.h"

class TextureManager
{
public: 
	static SDL_Texture* pLoadTexture(const char * pFileName);
	static void DrawMap(SDL_Texture * pTex, SDL_Rect src, SDL_Rect dst);
};

