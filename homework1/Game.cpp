#include "Game.h"
#include "Human.h"


Game::Game()
{
	std::cout << "The game has just begun" << std::endl;
}


Game::~Game()
{
	std::cout << "The game has just finished" << std::endl;
}


void Game::addHuman(std::shared_ptr<Human> human)
{
	humans.push_back(human);
}


void Game::updateHumansHealth(int humanId)
{
	for (auto human : humans)
	{
		if (human->getId() == humanId)
			continue;
		human->addHealthPoints(50);
	}
}


void Game::logGameState()
{
	for (auto human : humans)
	{
		std::cout << human->getName() << ": " << human->getHealthPoints() << " hp" << std::endl;
	}
	std::cout << std::endl;
}
