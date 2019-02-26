#include <utility>

#include "Doctor.h"

Doctor::Doctor(
		std::shared_ptr<Game> model,
		const std::string & name,
		int healthPoints,
		int maxHealthPoints
) : Human(std::move(model), name, healthPoints, maxHealthPoints)
{
}

Doctor::~Doctor() = default;

void Doctor::logTreatment()
{
	std::cout << "<Doctor> " << name << " is treating" << std::endl;
}
