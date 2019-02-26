#include <utility>

#include "Musician.h"

Musician::Musician(
		std::shared_ptr<Game> model,
		const std::string & name,
		int healthPoints,
		int maxHealthPoints
) : Human(std::move(model), name, healthPoints, maxHealthPoints)
{
}

Musician::~Musician() = default;

void Musician::logTreatment()
{
	std::cout << "<Musician> " << name << " is playing" << std::endl;
}
