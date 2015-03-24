#include <iostream>

#include "Cleanup.h"
#include "GameBase.h"

// outputs error and quit SDL
void output_error_sdl_quit(std::string error) {
	std::cout << error.c_str() << SDL_GetError() << std::endl;
	SDL_Quit();
}


// musing on sdl, using tutorial:
// - http://www.willusher.io/sdl2%20tutorials/2013/08/17/lesson-1-hello-world/
int main(int argc, char* args[])
{
	GameBase theGame;

	theGame.InitApp();
	theGame.EventLoop();
	theGame.Cleanup();

	return 0;
	return 0;
}