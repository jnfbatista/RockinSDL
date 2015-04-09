#pragma once
#include <vector>

#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <glm.hpp>

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
	
	// rotation area
	GLfloat angleRot = 0.0f;
	GLfloat targetAngle = angleRot; // for rotation animation purposes

	GLfloat rotationStep = 10.0f; // todo: better to adjust sensitivity (GUI?)


	// radius
	float objSize;

	// is marked for destruction
	bool destroy = false;
	
	// Hierarchy definition
	std::vector<Drawable> *children;

	Drawable* parent;

public:

	~Drawable();

	virtual bool Render() = 0;

	void UpdateRotation();

	glm::vec2 GetPosition() { return glm::vec2(xPos, yPos); }

	float GetRadius() { return objSize; }

	// destroy
	void Destroy() { destroy = true; }
	bool Destroyed() { return destroy; }
	
	Drawable* getParent() { return parent; }
	std::vector<Drawable>* getChildren() { return children; }
};

