#pragma once
#include "Drawable.h"
#include <SDL.h>

class Ship : Drawable
{
	float movementStep = 0.2f;

public:
	Ship();
	~Ship();


	void HandleKeyInput(SDL_KeyboardEvent keyEvent);

	bool Render() override;
};

