#ifndef CLEANUP_H
#define CLEANUP_H

#include <utility>
#include <SDL.h>

template<typename T, typename... Args>
void cleanup(T *t, Args&&... args) {
	// cleanup first item
	cleanup(t);

	// recursively cleanup the rest
	cleanup(std::forward<Args>(args)...);
}


/*
* implementation for each type of element
*/
template<>
void cleanup<SDL_Window>(SDL_Window *win) {
	if (!win){
		return;
	}
	SDL_DestroyWindow(win);
}
template<>
void cleanup<SDL_Renderer>(SDL_Renderer *ren){
	if (!ren){
		return;
	}
	SDL_DestroyRenderer(ren);
}
template<>
void cleanup<SDL_Texture>(SDL_Texture *tex){
	if (!tex){
		return;
	}
	SDL_DestroyTexture(tex);
}
template<>
void cleanup<SDL_Surface>(SDL_Surface *surf){
	if (!surf){
		return;
	}
	SDL_FreeSurface(surf);
}

// cleanup GL Context
template<>
void cleanup(SDL_GLContext *glContext) {
	if (!glContext) {
		return;
	}
	SDL_GL_DeleteContext(glContext);
}

#endif /* CLEANUP_H */