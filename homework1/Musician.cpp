#include "Musician.h"



Musician::Musician(
	Game* model,
	const std::string & name,
	int healthPoints,
	int maxHealthPoints
) : Human(model, name, healthPoints, maxHealthPoints)
{
}


Musician::~Musician()
{
}


void Musician::logTreatment()
{
	std::cout << "<Musician> " << name << " is playing" << std::endl;
}
