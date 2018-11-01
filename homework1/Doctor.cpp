#include "Doctor.h"


Doctor::Doctor(
	Game* model,
	const std::string & name,
	int healthPoints,
	int maxHealthPoints
) : Human(model, name, healthPoints, maxHealthPoints)
{
}


Doctor::~Doctor()
{
}


void Doctor::logTreatment()
{
	std::cout << "<Doctor> " << name << " is treating" << std::endl;
}
