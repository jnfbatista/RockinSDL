#pragma once
#include "Drawable.h"
#include  "Utils.h"

class Obstacle :  public Drawable
{

	GLUquadricObj * quadObject;


public:
	Obstacle();
	~Obstacle();


	bool Render() override;
	bool Render3D();

};

