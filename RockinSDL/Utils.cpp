#include "Utils.h"


float Utils::DegreesToRadians(float angle)
{
	return (angle * PI / 180.f);
}


// draws pentagon around 
// https://open.gl/drawing
void Utils::DrawPolygon(float radius, int slices)
{

	float currentAngle = 0;
	const float step = 360 / slices;
	std::vector<glm::vec3> vertices;

	for (int i = 0; i < slices; i++)
	{

		vertices.push_back(glm::vec3(radius * cos(DegreesToRadians(currentAngle)), radius * sin(DegreesToRadians(currentAngle)), 0));

		currentAngle += step;
	}


	glBegin(GL_POLYGON);

	for (int vertex = 0; vertex < vertices.size(); vertex++)
	{
		glVertex3f(vertices[vertex].x, vertices[vertex].y, vertices[vertex].z);
	}


	glEnd();

}

