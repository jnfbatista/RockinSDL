#include "Drawable.h"


Drawable::~Drawable()
{
}

void Drawable::UpdateRotation()
{
	if (angleRot != targetAngle)
	{

		if (abs(angleRot - targetAngle) < rotationStep)
		{
			angleRot = targetAngle;
			return;
		}
		else
		{
			if (angleRot < targetAngle)
			{
				angleRot += rotationStep;
				return;
			}
			else
			{
				angleRot -= rotationStep;
				return;
			}
		}

	
	}
	
}