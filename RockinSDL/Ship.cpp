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

void Ship::HandleKeyInput(SDL_KeyboardEvent keyEvent) {

	switch (keyEvent.keysym.sym) {

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
	}
	
}


bool Ship::Render()
{

	glPushMatrix();
	glColor3f(0.7, 0.5, 0.8);
	glRotatef(30, 0, 1, 1);
	glTranslatef(xPos, yPos, zPos);
	gluCylinder(quadObject, 1.0, 2.0, 10, 30, 30);

	glPopMatrix();
	return true;
}