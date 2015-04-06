#pragma once
#include "Drawable.h"
class Shot :
	public Drawable
{
public:
	Shot();
	~Shot();

	// Fire the shot
	void Fire();

	bool Render();
};

