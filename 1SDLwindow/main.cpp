
#include <SDL.h>
#include "Game.h"
#undef main

Game* game = nullptr;

int main(int argc, char* argv[]) {

	game = new Game();
	game->init("Engin", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, false);
	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	return 0;
}