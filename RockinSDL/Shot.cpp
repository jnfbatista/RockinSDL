#include "Shot.h"
#include "Utils.h"


Shot::Shot(GLfloat x, GLfloat y, GLfloat distance, GLfloat angle)
{
	xPos = x + radius * cos(Utils::DegreesToRadians(angle)) + radius;
	yPos = y + radius * sin(Utils::DegreesToRadians(angle)) + radius;
}


Shot::~Shot()
{
}

void Shot::Fire()
{
}

bool Shot::Render()
{
	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	Utils::DrawPolygon(radius, 40);

	glPopMatrix();

	return true;
}