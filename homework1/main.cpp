#include <iostream>
#include <memory>

#include "Game.h"
#include "Doctor.h"
#include "Grandmother.h"
#include "Musician.h"

int main()
{
	auto game = std::make_shared<Game>();
	auto doctor = std::make_shared<Doctor>(game, "Doctor", 800);
	auto grandmother = std::make_shared<Grandmother>(game, "Grandmother", 800);
	auto musician = std::make_shared<Musician>(game, "Musician", 800);
	game->addHuman(doctor);
	game->addHuman(grandmother);
	game->addHuman(musician);
	game->logGameState();
	
	doctor->applyAbility();
	game->logGameState();

	grandmother->applyAbility();
	game->logGameState();

	musician->applyAbility();
	game->logGameState();
	return 0;
}