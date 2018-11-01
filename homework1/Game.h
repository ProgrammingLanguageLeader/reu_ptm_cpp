#pragma once

#include <list>
#include <iostream>
#include <memory>

class Human;


class Game
{
	std::list<std::shared_ptr<Human>> humans;

public:
	Game();
	~Game();

	void addHuman(std::shared_ptr<Human> human);

	void updateHumansHealth(int humanId);

	void logGameState();
};

