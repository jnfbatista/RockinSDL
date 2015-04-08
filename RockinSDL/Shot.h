#pragma once
#include "Drawable.h"
class Shot :
	public Drawable
{

	GLfloat radius = 0.2f;

public:
	Shot(GLfloat x, GLfloat y, GLfloat distance, GLfloat angle);
	~Shot();

	// Fire the shot
	void Fire();

	bool Render() override;
};

