#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(const char* PtextureSheet, int x, int y);
	~GameObject();
	void Update();
	void Render();
private:
	int xpos;
	int ypos;

	SDL_Texture* pObjTexture;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* pRenderer;
};

