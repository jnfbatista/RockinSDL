#include "Shot.h"
#include "Utils.h"


Shot::Shot(GLfloat x, GLfloat y, GLfloat distance, GLfloat angle)
{
	objSize = 0.2f;

	float cx = cos(Utils::DegreesToRadians(angle));
	float cy = sin(Utils::DegreesToRadians(angle));

	xPos = x + distance * cx;
	yPos = y + distance * cy;

	direction = glm::normalize(glm::vec2(cx, cy));
}


Shot::~Shot()
{
}

bool Shot::Render()
{

	if (destroy && objSize < 0.0f)
		return false;
	
	if (!destroy)
	{
		UpdatePosition();
	}
	else
	{
		objSize -= 0.05f;
	}

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	Utils::DrawPolygon(objSize, 40);

	glPopMatrix();

	return true;
}

void Shot::UpdatePosition()
{
	xPos += linearSpeed * direction.x;
	yPos += linearSpeed * direction.y;
}