#include <utility>

#include "Human.h"

int Human::freeHumanId = 1;

Human::Human(
		std::shared_ptr<Game> model,
		const std::string & name,
		int healthPoints,
		int maxHealthPoints
)
{
	this->id = freeHumanId++;
	this->model = std::move(model);
	this->name = name;
	this->healthPoints = healthPoints;
	this->maxHealthPoints = maxHealthPoints;
}

Human::~Human() = default;

void Human::logTreatment()
{
	std::cout << "<Human> " << name << " is treating" << std::endl;
}

void Human::applyAbility()
{
	subHealthPoints(50);
	logTreatment();
	notifyModel(id);
}

void Human::notifyModel(int id)
{
	model->updateHumansHealth(id);
}
