#pragma once
#include <vector>

#include <SDL_opengl.h>
#include <GL\GLU.h>

class Drawable
{

protected:


	GLUquadricObj *quadObject;

	GLfloat xPos = 0.0f;
	GLfloat yPos = 0.0f;
	GLfloat zPos = 0.0f;
	
	GLfloat xRot = 0.0f;
	GLfloat yRot = 0.0f;
	GLfloat zRot = 0.0f;
	
	GLfloat angleRot = 0.0f;

	std::vector<Drawable> *children;

	Drawable* parent;

public:

	~Drawable();

	virtual bool Render() = 0;

	Drawable* getParent() { return parent; }
	std::vector<Drawable>* getChildren() { return children; }
};

