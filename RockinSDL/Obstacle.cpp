#include "Obstacle.h"

Obstacle::Obstacle()
{
	obsSize = static_cast<float> (rand() % 5) / 5.f;

	//  randomize position
	yPos = 0.5f;

	int randVal = rand() % 20;
	xPos = static_cast<float> (randVal)-10.f;
	zPos = -(rand() % 20) - 10.f;

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
	Move();

	glPushMatrix();


	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(xPos, yPos, 1);
	Utils::DrawPolygon(obsSize, 5);
	
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
	zPos += 0.05;

	return true;
}