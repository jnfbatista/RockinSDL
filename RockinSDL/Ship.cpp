#include "Ship.h"


Ship::Ship()
{
	quadObject = gluNewQuadric();
	shots = new std::vector<Shot>();

	drag = 0.001f;

	// start at center position
	xPos = 6.0f;
	yPos = 4.5f;

	// define radius
	objSize = 0.5f;

}


Ship::~Ship()
{
	// delete quadric
	gluDeleteQuadric(quadObject);
}

void Ship::HandleKeyInput(const Uint8 * keysState) {

	glm::vec2 accelerateDirection;

	if (keysState[SDL_SCANCODE_W])
	{
		//yPos += movementStep;
		accelerateDirection.y = 1;
	}
	if (keysState[SDL_SCANCODE_A])
	{
		//xPos -= movementStep;
		accelerateDirection.x = -1;
	}
	if (keysState[SDL_SCANCODE_S])
	{
		//yPos -= movementStep;
		accelerateDirection.y = -1;
	}
	if (keysState[SDL_SCANCODE_D])
	{
		//xPos += movementStep;
		accelerateDirection.x = 1;
	}

	if (keysState[SDL_SCANCODE_J])
	{
		Shoot(0); // shots fired!!
	}
	if (keysState[SDL_SCANCODE_K])
	{
		Shoot(1); // shots fired!!
	}
	if (keysState[SDL_SCANCODE_L])
	{
		Shoot(2); // shots fired!!
	}


	// rotation
	if (keysState[SDL_SCANCODE_SPACE])
	{
		// rotate 45ª
		targetAngle = angleRot + 45;
	}
	if (keysState[SDL_SCANCODE_LEFT])
	{
		targetAngle = angleRot - 5;
	}
	if (keysState[SDL_SCANCODE_RIGHT])
	{
		targetAngle = angleRot + 5;
	}

	// movement
	if (accelerateDirection.x != 0 || accelerateDirection.y != 0)
	{
		Accelerate(accelerateDirection);
	}
}



bool Ship::Render()
{

	// if out of bounds easy cheat 
	if (xPos + objSize < 0.f)
		xPos = 12.f + objSize;
	else if (xPos - objSize > 12.f)
		xPos = 0.f + objSize;

	if (yPos + objSize < 0.f)
		yPos = 9.f + objSize;
	else if (yPos - objSize > 9.f)
		yPos = 0.f + objSize;

	UpdateSpeed();
	UpdateRotation();

	xPos += velocity.x;
	yPos += velocity.y;

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(angleRot, 0, 0, 1);

	glColor3f(0.7, 0.5, 0.8);
	Utils::DrawPolygon(objSize, 3);


	

	glPopMatrix();



	// render shots

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

void Ship::HandleMouseInput(SDL_MouseButtonEvent sdlMouseButtonEvent)
{
	switch (sdlMouseButtonEvent.button)
	{
	case SDL_BUTTON_LEFT:

		Shoot(0);
		break;
	case SDL_BUTTON_MIDDLE:
		Shoot(1);
		break;

	case SDL_BUTTON_RIGHT:
		Shoot(2);
		break;

	}
}

std::vector<Shot>* Ship::GetShots()
{
	return shots;
}

void Ship::Shoot(int vertex)
{

	shots->push_back(Shot(xPos, yPos, objSize, angleRot + 120 * vertex));

}