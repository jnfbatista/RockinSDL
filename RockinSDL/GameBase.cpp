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
// check - https://www.opengl.org/archives/resources/faq/technical/viewing.htm
// and - http://www.tomdalling.com/blog/modern-opengl/03-matrices-depth-buffering-animation/
void GameBase::InitApp(void)
{
	//let's roll the dice
	srand(static_cast<unsigned>(time(nullptr)));

	// Initialize window
	InitializeSDL(800, 600);

	// initalize game objects
	ship = new Ship();
	obstacles = new std::vector<Obstacle*>();

	for (int i = 0; i < 10; i++)
		obstacles->push_back(new Obstacle());


	if (!bonusMode)
	{
		DefineOrthographicProjection(12, 9); // TODO: remove magic numbers it should be a ratio thing
	}
	else
	{
		Define3DProjection();
	}



	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);


	InstallTimer();

}

void GameBase::InitializeSDL(Uint32 wWidth, Uint32 wHeight)
{
	width = wWidth;
	height = wHeight;

	int error = SDL_Init(SDL_INIT_EVERYTHING);
	// Turn on double buffering.
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Create the window
	mainWindow = SDL_CreateWindow("Stuff!!!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	mainGLContext = SDL_GL_CreateContext(mainWindow);

}


// 2D game mode
void GameBase::DefineOrthographicProjection(GLfloat width, GLfloat height)
{
	glOrtho(0.0, width, 0.0, height, -1.0, 100.0);
}

// 3D Game mode
void GameBase::Define3DProjection()
{

	//Initialize Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, 800/600, 3.0, 105.0);

	//Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		0.0, 10.0, 10.0, // eye
		0.0, 0.0, 0.0, // looking at
		0.0, 1.0, 0.0); // up vector (wtf m8)
}


void GameBase::InstallTimer(void)
{
	timer = SDL_AddTimer(60, GameLoopTimer, this);
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

		case SDL_KEYDOWN: // KEY DOWN!! I REPEAT: WE HAVE KEY DOWN!
			HandleKeys(event.key);
			break;

		case SDL_MOUSEBUTTONDOWN:
			HandleMouse(event.button);
			break;

		case SDL_QUIT:
			done = true;
			break;

		default:
			break;
		}   // End switch

	}   // End while

}

void GameBase::HandleKeys(SDL_KeyboardEvent keyEvent) {
	switch (keyEvent.keysym.sym) {
	case SDLK_q:
		done = true;
		break;
	}

	// handle ship input
	ship->HandleKeyInput(keyEvent.keysym.sym);
}


void GameBase::HandleMouse(SDL_MouseButtonEvent sdlMouseButtonEvent)
{
	ship->HandleMouseInput(sdlMouseButtonEvent);
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

	glPushMatrix();

	ship->Render();

	glPopMatrix();

	// render obstacles
	std::vector<Obstacle*>::iterator it;
	for (it = obstacles->begin(); it != obstacles->end(); ++it)
	{
		(*it)->Render();
	}
		

	SDL_GL_SwapWindow(mainWindow);
}


void GameBase::RenderGround() {

	//glcol
	// TRIANGLES!!! 'Sup
	glBegin(GL_TRIANGLE_STRIP);
	
	for (int z = groundStart; z < groundEnd; z++)
	{
		for (int x = groundStart; x < groundEnd; x++)
		{

			glColor3ub(100, 255, 100);
			glVertex3f(x, 0, z);

			glVertex3f(x + 1, 0, z);

			glVertex3f(x, 0, z + 1);


			glVertex3f(x +1, 0, z+1);

			glVertex3f(x + 1, 0, z);

			glVertex3f(x, 0, z + 1);


		}
	}

	glEnd();
}
