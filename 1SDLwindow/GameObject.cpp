#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* pTextureSheet, int x, int y)
{
	xpos = x;
	xpos = y;
	pObjTexture = TextureManager::pLoadTexture(pTextureSheet);
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	++xpos;
	++ypos;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.y = 0;
	srcRect.x = 0;

	dstRect.x = xpos;
	dstRect.y = ypos;
	dstRect.w = srcRect.w * 2;
	dstRect.h = srcRect.h * 2;




}

void GameObject::Render()
{
	SDL_RenderCopy(Game::pRenderer, pObjTexture, &srcRect, &dstRect);
}
