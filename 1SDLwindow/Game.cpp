#include "Game.h"
#include <iostream>

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
}

void Game::update()
{
	++cnt;
	std::cout << cnt << std::endl;
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
	// this is where we would add stuff to render
	SDL_RenderPresent(pRenderer);
}

bool Game::running()
{
	return isRunning;
}


