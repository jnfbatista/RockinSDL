#include "Ship.h"


Ship::Ship()
{
	quadObject = gluNewQuadric();
	shots = new std::vector<Shot*>();

	// start at center position
	xPos = 6.0f;
	yPos = 4.5f;

	
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

	if (keysState[SDL_SCANCODE_SPACE])
	{
		// shots fired!!
		Shoot();
	}

	// rotation
	if (keysState[SDL_SCANCODE_R])
	{
		// rotate 45ª
		targetAngle = angleRot + 45;
	}
	if (keysState[SDL_SCANCODE_LEFT])
	{
		targetAngle = angleRot - rotationStep;
	}
	if (keysState[SDL_SCANCODE_RIGHT])
	{
		targetAngle = angleRot + rotationStep;
	}


	// movement
	if (accelerateDirection.x != 0 || accelerateDirection.y != 0)
	{
		Accelerate(accelerateDirection);
	}


}



bool Ship::Render()
{
	UpdateSpeed();
	UpdateRotation();

	xPos += velocity.x;
	yPos += velocity.y;

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(angleRot, 0, 0, 1);

	glColor3f(0.7, 0.5, 0.8);
	Utils::DrawPolygon(0.5f, 3);


	std::vector<Shot*>::iterator it;
	
	glPopMatrix();

	// render shots
	for (it = shots->begin(); it != shots->end(); ++it)
	{
		(*it)->Render();
	}


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
	case SDL_BUTTON_MIDDLE:
		//sdlMouseButtonEvent.
		break;

	case SDL_BUTTON_LEFT:

		break;

	case SDL_BUTTON_RIGHT:

		break;


	}
}

void Ship::Shoot()
{
	shots->push_back(new Shot(xPos, yPos, 0.5f, angleRot));

}