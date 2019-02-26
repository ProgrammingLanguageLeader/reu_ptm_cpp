#pragma once

#include <string>
#include <iostream>

#include "Human.h"

class Musician :
	public Human
{
public:
	Musician(
			std::shared_ptr<Game> model,
			const std::string & name,
			int healthPoints = Human::DEFAULT_HEALTH_POINTS,
			int maxHealthPoints = Human::DEFAULT_MAX_HEALTH_POINTS
	);
	~Musician();

	void logTreatment() override;
};
