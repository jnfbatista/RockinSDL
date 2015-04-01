#include "Ship.h"


Ship::Ship()
{
	quadObject = gluNewQuadric();
}


Ship::~Ship()
{

	// delete quadric
	gluDeleteQuadric(quadObject);
}

void Ship::HandleKeyInput(SDL_Keycode keyCode) {

	switch (keyCode) {

	case SDLK_a:
		xPos -= movementStep;
		break;
	case SDLK_d:
		xPos += movementStep;
		break;
	case SDLK_w:
		yPos += movementStep;
		break;
	case SDLK_s:
		yPos -= movementStep;
		break;
	default:
		break;
	}

}

bool Ship::Render()
{
	glPushMatrix();


	glTranslatef(xPos, yPos, zPos);

	Utils::DrawPolygon(0.5f, 3);

	glPopMatrix();

	return true;
}

bool Ship::Render3D()
{

	glPushMatrix();
	glColor3f(0.7, 0.5, 0.8);
	//glRotatef(30.0f, 1, 0, 0);
	glTranslatef(xPos, yPos, zPos);

	gluCylinder(quadObject, 0.0f, 0.5f, 1, 30, 30);

	glPopMatrix();
	return true;
}