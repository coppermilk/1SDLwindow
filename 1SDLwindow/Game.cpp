#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include "Map.h"

#include "GameObject.h"
#include "ECS.h"
#include "Componets.h"

GameObject* pPlayer;
GameObject* pEnemy;
Map* pMap;
SDL_Renderer* Game::pRenderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game()
{
}

Game::~Game()
{
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::init(const char* title, int xpos, int ypos, int width, int heigt, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Sybsystem Initialised...\n";
		pWindow = SDL_CreateWindow(title, xpos, ypos, width, heigt, flags);
		if (pWindow) {
			std::cout << "Window created.\n";
		}
		pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
		if (pRenderer) {
			SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
			std::cout << "Render created.\n";
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	pPlayer = new GameObject("assets/player.png", 42, 42);
	pEnemy = new GameObject("assets/enemy.png", 82, 82);
	pMap = new Map();
	newPlayer.addComponent<PositionComponets>();
	

}
void Game::update()
{
	pPlayer->Update();
	pEnemy->Update();
	manager.update();
	std::cout << newPlayer.getComponent<PositionComponets>().x() << "," << newPlayer.getComponent<PositionComponets>().y() << std::endl;
	
	
}

void Game::clean()
{
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	SDL_Quit();
	std::cout << "Game cleaned\n";

}

void Game::render()
{
	SDL_RenderClear(pRenderer);
	pMap->DrawMap();
	pPlayer->Render();
	pEnemy->Render();
	SDL_RenderPresent(pRenderer);

}

bool Game::running()
{
	return isRunning;
}


