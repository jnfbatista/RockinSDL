#pragma once
#include "Drawable.h"
class Obstacle :  public Drawable
{

	GLUquadricObj * quadObject;


public:
	Obstacle();
	~Obstacle();


	bool Render();

};

