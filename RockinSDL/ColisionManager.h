#pragma once
#include "Ship.h"
#include "Obstacle.h"

class ColisionManager
{

	Ship* ship;
	std::vector<Obstacle>* obstacles;
	std::vector<Shot > * shots;

	float xViewport;
	float yViewport;

public:
	ColisionManager(Ship * ship, std::vector<Obstacle> *obstacles, std::vector<Shot> * shots);

	void SetBoundaries(float x, float y);

	void CalculateColisions();
	
	~ColisionManager();
};

