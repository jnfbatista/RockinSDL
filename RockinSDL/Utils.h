#pragma once

#include <SDL_opengl.h>
#include <glm.hpp>
#include <math.h>
#include <GL\GLU.h>
#include <vector>

#define PI 3.14159265


class Utils
{
public:

	static void DrawEquilateralRectangle(GLfloat side);

	static float DegreesToRadians(float angle);

	static void DrawPolygon(float radius, int slices);

	Utils();
	~Utils();
};

