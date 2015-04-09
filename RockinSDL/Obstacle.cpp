#include "Obstacle.h"

Obstacle::Obstacle()
{
	objSize = static_cast<float> (rand() % 5) / 5.f;

	//  randomize position
	yPos = static_cast<float> (rand() % 9);
	xPos = static_cast<float> (rand() % 12);
	zPos = 0.f;

	// define speed and direction
	// this should be updated in an AI kind of idea
	speed = static_cast<float>(rand() % 10) * 0.1f;

	movementDirection = glm::diskRand(1.0f);


}


Obstacle::~Obstacle()
{
}


void Obstacle::Move()
{
	// straight line
	xPos += speed * movementDirection.x;
	yPos += speed * movementDirection.y;
}



bool Obstacle::Render()
{


	if (destroy && objSize < 0.0f)
		return false;

	if (!destroy)
	{
		Move();
	}
	else
	{
		objSize -= 0.05f;
	}	

	glPushMatrix();


	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(xPos, yPos, 1);
	Utils::DrawPolygon(objSize, 5);
	
	glPopMatrix();

	return true;
}

bool Obstacle::Render3D()
{
	glPushMatrix();

	//glClearColor()

	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(xPos, 1, zPos);
	gluSphere(quadObject, 0.5, 30, 30);

	glPopMatrix();

	// update position based on speed
	zPos += 0.05f;

	return true;
}