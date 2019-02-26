#include <utility>

#include "Grandmother.h"

Grandmother::Grandmother(
		std::shared_ptr<Game> model,
		const std::string & name,
		int healthPoints,
		int maxHealthPoints
) : Human(std::move(model), name, healthPoints, maxHealthPoints)
{
}

Grandmother::~Grandmother() = default;

void Grandmother::logTreatment()
{
	std::cout << "<Grandmother> " << name << " is feeding" << std::endl;
}
