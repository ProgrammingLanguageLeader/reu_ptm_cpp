#pragma once

#include <iostream>
#include <string>

#include "Human.h"

class Grandmother :
	public Human
{
public:
	Grandmother(
			std::shared_ptr<Game> model,
			const std::string & name,
			int healthPoints = Human::DEFAULT_HEALTH_POINTS,
			int maxHealthPoints = Human::DEFAULT_MAX_HEALTH_POINTS
	);
	~Grandmother();

	void logTreatment() override;
};
