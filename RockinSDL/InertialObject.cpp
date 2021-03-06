#include "InertialObject.h"

void InertialObject::Accelerate(glm::vec2 direction)
{
	// normalize vector
	direction = glm::normalize(direction);

	velocity.x += accelerationRate * direction.x;
	velocity.y += accelerationRate * direction.y;

}

void InertialObject::UpdateSpeed()
{

	if (velocity.x < 0)
	{
		if (velocity.x + drag >= 0)
		{
			velocity.x = 0;
		}
		else
		{
			velocity.x += drag;
		}
	}
	else if (velocity.x > 0)
	{
		if (velocity.x - drag <= 0)
		{
			velocity.x = 0;
		}
		else
		{
			velocity.x -= drag;
		}
	}

	if (velocity.y < 0)
	{
		if (velocity.y + drag >= 0)
		{
			velocity.y = 0;
		}
		else
		{
			velocity.y += drag;
		}
	}
	else if (velocity.y > 0)
	{
		if (velocity.y - drag <= 0)
		{
			velocity.y = 0;
		}
		else
		{
			velocity.y -= drag;
		}
	}

}