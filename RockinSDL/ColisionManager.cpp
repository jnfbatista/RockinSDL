#include "ColisionManager.h"


ColisionManager::ColisionManager(Ship* s, std::vector<Obstacle>* obs, std::vector<Shot> * sh)
{
	ship = s;
	obstacles = obs;
	shots = sh;
}

void ColisionManager::SetBoundaries(float x, float y)
{
	xViewport = x;
	yViewport = y;
}

void ColisionManager::CalculateColisions()
{
	// check shots and obstacles (dumb, bruteforce)
	for (size_t s = 0; s < shots->size(); s++)
	{
		Shot *shot = &shots->at(s);
		glm::vec2 shotPos = shot->GetPosition();

		if (shot->Destroyed()) // ignore destroyed objects
			continue;

		// out of boundaries
		if (shotPos.x + shot->GetRadius() < 0.f || shotPos.x - shot->GetRadius() >= xViewport || 
			shotPos.y + shot->GetRadius() < 0.f || shotPos.y - shot->GetRadius() >= yViewport)
		{
			shot->Destroy();
			continue;
		}
			

		for (size_t o = 0; o < obstacles->size(); o++)
		{
			Obstacle * obs = &obstacles->at(o);
			glm::vec2 obsPosition = obs->GetPosition();

			if (obs->Destroyed()) // ignore destroyed objects
				continue;

			// out of boundaries
			if (obsPosition.x + obs->GetRadius() < 0.f || obsPosition.x - obs->GetRadius() >= xViewport ||
				obsPosition.y + obs->GetRadius() < 0.f || obsPosition.y - obs->GetRadius() >= yViewport)
			{
				obs->Destroy();
				continue;
			}
			
			float maxDistance = shot->GetRadius() + obs->GetRadius();

			if (glm::distance(shotPos, obsPosition) <=  maxDistance)
			{
				// destroy both
				shot->Destroy();
				obs->Destroy();
			}
		}
	}


}

ColisionManager::~ColisionManager()
{
}
