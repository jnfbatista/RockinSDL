#ifndef CAMERA_H
#define CAMERA
#pragma once
class Camera
{

private:

	

public:
	Camera();

	~Camera();

	bool Rotate(float angle, float x, float y, float z);

	bool Translate(float x, float y, float z);

};

#endif