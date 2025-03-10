
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include <SDL_gamecontroller.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

inline void init();
inline void GameLoop();
inline void close();


int main(int argc , char * argv[])
{
	init();
	
	GameLoop();

	close();

	return 0;
}

inline void init()
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	//IMG_INIT(IMG_INIT_JPG | IMG_INIT_PNG);
}

inline void GameLoop()
{
	GameSystem::Game Game("Chess", WINDOW_WIDTH, WINDOW_HEIGHT);
	while (Game.isRunning())
	{
		Game.update();
		Game.pollEvent();
		Game.render();

	}
}

inline void close()
{
	SDL_Quit();
	IMG_Quit();
}