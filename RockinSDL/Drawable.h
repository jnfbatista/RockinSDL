#pragma once
#include <vector>

#include <SDL_opengl.h>
#include <GL\GLU.h>

class Drawable
{

protected:


	GLUquadricObj *quadObject;

	float xPos = 0.0f;
	float yPos = 0.0f;
	float zPos = 0.0f;

	float xRot = 0.0f;
	float yRot = 0.0f;
	float zRot = 0.0f;

	float angleRot = 0.0f;

	std::vector<Drawable> *children;

	Drawable* parent;

public:

	~Drawable();

	virtual bool Render() = 0;

	Drawable* getParent() { return parent; }
	std::vector<Drawable>* getChildren() { return children; }
};

