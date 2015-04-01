#pragma once
#include <SDL.h>

#include "Drawable.h"
#include "Utils.h"

class Ship : Drawable
{
	float movementStep = 0.2f;

public:
	Ship();
	~Ship();

	void HandleKeyInput(SDL_Keycode keyCode);

	bool Render() override;
	bool Render3D();
	void HandleMouseInput(SDL_MouseButtonEvent sdlMouseButtonEvent);
};

