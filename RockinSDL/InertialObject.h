#pragma once
#include <glm.hpp>

class InertialObject
{
protected:
	float maxLinearSpeed = 0.8f;

	// drag coefficient is considered
	float drag = 0.005f;

	// Current speed
	glm::vec2 velocity = glm::vec2(0.f, 0.f);

	// current acceleration
	float accelerationRate = 0.01f;

	// maximum acceleration
	float maxAcceleration;

public:

	void Accelerate(glm::vec2 direction);

	void UpdateSpeed();
};

