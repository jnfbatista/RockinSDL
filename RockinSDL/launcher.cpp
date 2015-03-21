#include <SDL.h>
#include <iostream>
#include "Cleanup.h"

// outputs error and quit SDL
void output_error_sdl_quit(std::string error) {
	std::cout << error.c_str() << SDL_GetError() << std::endl;
	SDL_Quit();
}


// musing on sdl, using tutorial:
// - http://www.willusher.io/sdl2%20tutorials/2013/08/17/lesson-1-hello-world/
int main(int argc, char* args[])
{
	// init sdl window 
	if (SDL_Init(SDL_INIT_VIDEO) != 0) { // you failed
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	// create window
	SDL_Window * window = SDL_CreateWindow("Arkanoid", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	if (window == nullptr) { // you failed again
		cleanup(window);
		output_error_sdl_quit("SDL_CreateWindow failed: ");
		return 1;
	}

	// it's the renderer time
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		cleanup(window);
		output_error_sdl_quit("Renderer creation failed: ");
		return 1;

	}

	// lets load an image
	std::string imgPath = "hello.bmp";

	SDL_Surface *bmp = SDL_LoadBMP(imgPath.c_str());
	if (bmp == nullptr) {
		cleanup(renderer, window);
		output_error_sdl_quit("unable to load image: ");
		return -1;
	}

	// set the image to a texture (wasn't that hard)
	SDL_Texture * tex = SDL_CreateTextureFromSurface(renderer, bmp);
	SDL_FreeSurface(bmp);

	if (tex == nullptr) {
		cleanup(window, renderer, tex);
		output_error_sdl_quit("SDL_CreateTextureFromSurface Error: ");
		return 1;
	}

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, tex, NULL, NULL);
	SDL_RenderPresent(renderer);

	SDL_Delay(2000);

	return 0;
}