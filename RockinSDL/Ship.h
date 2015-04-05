#pragma once
#include <SDL.h>

#include "Drawable.h"
#include "Utils.h"
#include "InertialObject.h"

class Ship : Drawable, InertialObject
{
	float movementStep = 0.2f;

	// for rotation animation purposes
	

public:
	Ship();
	~Ship();

	void HandleKeyInput(const Uint8 * keysState);

	bool Render() override;
	bool Render3D();
	void HandleMouseInput(SDL_MouseButtonEvent sdlMouseButtonEvent);
};

