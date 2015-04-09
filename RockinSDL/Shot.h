#pragma once
#include "Drawable.h"
class Shot :
	public Drawable
{

	GLfloat linearSpeed = 0.5f;
	glm::vec2 direction;

public:
	// Fire the shot
	Shot(GLfloat x, GLfloat y, GLfloat distance, GLfloat angle);
	~Shot();

	
	bool Render() override;

	void UpdatePosition();
};

