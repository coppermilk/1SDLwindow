#pragma once
#include <SDL.h>
#include <SDL_image.h>
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
	int cnt;
	bool isRunning;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
};
