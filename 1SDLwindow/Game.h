#pragma once
#include <SDL.h>
class Game
{
public:
	Game();
	~Game();
	void handleEvents();
	void init(const char* title, int xpos, int ypos, int width, int heigt, bool fullscreen);
	void update();
	void clean();
	void render();
	

	bool running();
private:
	bool isRunning;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
};
