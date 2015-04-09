#pragma once
#include <SDL.h>

#include "Drawable.h"
#include "Utils.h"
#include "InertialObject.h"
#include "Shot.h"

class Ship : Drawable, InertialObject
{
	float movementStep = 0.2f;


	std::vector<Shot> *shots;

public:
	Ship();
	~Ship();

	void HandleKeyInput(const Uint8 * keysState);

	bool Render() override;
	bool Render3D();
	void HandleMouseInput(SDL_MouseButtonEvent sdlMouseButtonEvent);

	std::vector<Shot>* GetShots();

	void Shoot(int vertex);
};

