#pragma once

#include <iostream>
#include <string>

#include "Human.h"

class Doctor : public Human
{
public:
	Doctor(
			std::shared_ptr<Game> model,
			const std::string & name,
			int healthPoints = Human::DEFAULT_HEALTH_POINTS,
			int maxHealthPoints = Human::DEFAULT_MAX_HEALTH_POINTS
	);
	~Doctor();

	void logTreatment() override;
};
