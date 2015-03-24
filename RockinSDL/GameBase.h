#pragma once
#ifndef GAME_BASE_H
#define GAME_BASE_H
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>


class GameBase
{
protected:
	SDL_Window* mainWindow;
	SDL_GLContext mainGLContext;
	SDL_TimerID timer;
	bool done;

	GLUquadricObj *quadObject;

public:
	// Constructor and destructor
	GameBase(void);
	virtual ~GameBase(void);

	// Initialization functions
	void InitApp(void);
	void InitializeSDL(Uint32 width, Uint32 height);
	void CreateOrthographicProjection(GLfloat width, GLfloat height);
	void InstallTimer(void);
	static Uint32 GameLoopTimer(Uint32 interval, void* param);

	// Cleanup functions
	void Cleanup(void);

	// Event-related functions
	void EventLoop(void);
	void HandleUserEvents(SDL_Event* event);

	// Game related functions
	void GameLoop(void);
	void RenderFrame(void);
};

typedef GameBase* GameAppPtr;
typedef GameBase** GameAppHandle;

const int RUN_GAME_LOOP = 1;

#endif /* GAME_BASE_H */