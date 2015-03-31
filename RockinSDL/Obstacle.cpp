#include "Obstacle.h"


Obstacle::Obstacle()
{


	quadObject = gluNewQuadric();

	yPos = 0.5f;


	int randVal = rand() % 20;
	xPos = static_cast<float> (randVal)-10.f;
	zPos = -(rand() % 20) - 10.f;

}


Obstacle::~Obstacle()
{
}

bool Obstacle::Render()
{
	glPushMatrix();

	//glClearColor()

	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(xPos, 1, zPos);
	gluSphere(quadObject, 0.5, 30, 30);

	glPopMatrix();

	// update position based on speed
	zPos += 0.05;

	return true;
}