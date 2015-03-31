#include "Obstacle.h"


Obstacle::Obstacle()
{


	quadObject = gluNewQuadric();



	yPos = 10.0f;


	xPos =  0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (5 - 0)));
	zPos = 0.0f;

}


Obstacle::~Obstacle()
{
}

bool Obstacle::Render()
{
	glPushMatrix();
	glColor3f(100, 1, 1);
	glTranslatef(xPos, yPos, zPos);
	gluSphere(quadObject, 1, 30, 30);

	glPopMatrix();

	return true;
}