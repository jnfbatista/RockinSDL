#pragma once
#include "Drawable.h"
#include  "Utils.h"
#include <gtc/random.hpp>

class Obstacle :  public Drawable
{
	GLUquadricObj * quadObject;
	

	float speed;
	glm::vec2 movementDirection;

	void Move();

public:
	Obstacle();
	~Obstacle();


	bool Render() override;
	bool Render3D();

};

