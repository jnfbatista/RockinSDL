#pragma once
class Camera 
{
	float xPos = 0.0f;
	float yPos = 0.0f;
	float zPos = 0.0f;

	float xRot = 0.0f;
	float yRot = 0.0f;
	float zRot = 0.0f;

	float angleRot = 0.0f;

public:
	Camera();

	~Camera();
	void Render();


	bool Rotate(float angle, float x, float y, float z);

	bool Translate(float x, float y, float z);

};