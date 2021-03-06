#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>

#include <time.h>

#include "Ship.h"
#include "Obstacle.h"
#include "ColisionManager.h"


class GameBase
{
	Uint32 width;
	Uint32 height;

	// 3D mode (hopefully not wishful thinking)
	bool bonusMode = false;

	int groundStart = -100;
	int groundEnd = 100;

	

protected:
	SDL_Window* mainWindow;
	SDL_GLContext mainGLContext;
	SDL_TimerID timer;
	bool done;

	// game objects
	Ship* ship;
	std::vector<Obstacle>* obstacles;
	std::vector<Shot> *shots;

	ColisionManager* collisionManager;
	
	void HandleKeys(SDL_KeyboardEvent keyEvent);

	// handle ground drawing
	void RenderGround();

public:
	// Constructor and destructor
	GameBase(void);
	virtual ~GameBase(void);

	// Initialization functions
	void InitApp(void);
	void InitializeSDL(Uint32 width, Uint32 height);

	// Projections
	void DefineOrthographicProjection(GLfloat width, GLfloat height);
	void Define3DProjection();


	void InstallTimer(void);
	static Uint32 GameLoopTimer(Uint32 interval, void* param);

	// Cleanup functions
	void Cleanup(void);

	void HandleMouse(SDL_MouseButtonEvent sdlMouseButtonEvent);
	// Event-related functions
	void EventLoop(void);
	void HandleUserEvents(SDL_Event* event);

	// Game related functions
	void GameLoop(void);
	void RenderFrame(void);
};

const int RUN_GAME_LOOP = 1;
