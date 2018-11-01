#include "Grandmother.h"


Grandmother::Grandmother(
	Game* model,
	const std::string & name,
	int healthPoints,
	int maxHealthPoints
) : Human(model, name, healthPoints, maxHealthPoints)
{
}


Grandmother::~Grandmother()
{
}


void Grandmother::logTreatment()
{
	std::cout << "<Grandmother> " << name << " is feeding" << std::endl;
}
