#include "GameBase.h"

// Constructor
GameBase::GameBase(void)
{
	done = false;
}

// Destructor
GameBase::~GameBase(void)
{
	Cleanup();
}


// Initialization functions
void GameBase::InitApp(void)
{
	// Create a 640 by 480 window.
	InitializeSDL(640, 480);

	//Initialize Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, 1.0, 3.0, 7.0);

	//Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		0.0, 0.0, 5.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

	//CreateOrthographicProjection(4.0, 3.0);

	
	

	// define the view 
	//gluLookAt(10, 10, -10, 0, 0, 0, 0.0, 1.0, 0.0);
	//glFrustum(-0.50, 0.50, -0.50, 0.50, 1.0, 3.0);

	quadObject = gluNewQuadric();

	InstallTimer();

}

void GameBase::InitializeSDL(Uint32 width, Uint32 height)
{
	int error;

	error = SDL_Init(SDL_INIT_EVERYTHING);
	// Turn on double buffering.
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Create the window
	mainWindow = SDL_CreateWindow("Stuff!!!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	mainGLContext = SDL_GL_CreateContext(mainWindow);

}


/*
* this is great for 2D Games, not what we want
*/
void GameBase::CreateOrthographicProjection(GLfloat width, GLfloat height)
{
	glOrtho(0.0, width, 0.0, height, -1.0, 100.0);
}

void GameBase::InstallTimer(void)
{
	timer = SDL_AddTimer(30, GameLoopTimer, this);
}

Uint32 GameBase::GameLoopTimer(Uint32 interval, void* param)
{
	// Create a user event to call the game loop.
	SDL_Event event;

	event.type = SDL_USEREVENT;
	event.user.code = RUN_GAME_LOOP;
	event.user.data1 = 0;
	event.user.data2 = 0;

	SDL_PushEvent(&event);

	return interval;
}


// Cleanup functions
void GameBase::Cleanup(void)
{
	SDL_bool success;
	success = SDL_RemoveTimer(timer);

	SDL_GL_DeleteContext(mainGLContext);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}


// Event-related functions
void GameBase::EventLoop(void)
{
	SDL_Event event;

	while ((!done) && (SDL_WaitEvent(&event))) {
		switch (event.type) {
		case SDL_USEREVENT:
			HandleUserEvents(&event);
			break;

		case SDL_KEYDOWN:
			// Quit when user presses a key.
			done = true;
			break;

		case SDL_QUIT:
			done = true;
			break;

		default:
			break;
		}   // End switch

	}   // End while

}

void GameBase::HandleUserEvents(SDL_Event* event)
{
	switch (event->user.code) {
	case RUN_GAME_LOOP:
		GameLoop();
		break;

	default:
		break;
	}
}


// Game related functions
void GameBase::GameLoop(void)
{
	RenderFrame();
}

void GameBase::RenderFrame(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glRectf(1.0, 1.0, 3.0, 2.0);

	glPushMatrix();


	//glTranslatef(10, 10, 0);
	glColor3f(0.7, 0.5, 0.8);
	glRotatef(30, 0, 1, 0);
	gluCylinder(quadObject, 1.0, 1.0, 10, 30, 30);

	glPopMatrix();
	SDL_GL_SwapWindow(mainWindow);
}
