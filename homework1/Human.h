#pragma once

#include <iostream>
#include <string>
#include <algorithm>

#include "Game.h"


class Human
{
private:
	static int freeHumanId;
	int id;

protected:
	Game* model;
	std::string name;
	int maxHealthPoints;
	int healthPoints;

public:
	static const int DEFAULT_MAX_HEALTH_POINTS = 1000;
	static const int DEFAULT_HEALTH_POINTS = DEFAULT_MAX_HEALTH_POINTS;

	Human(
		Game* model, 
		const std::string & name, 
		int healthPoints = DEFAULT_HEALTH_POINTS, 
		int maxHealthPoints = DEFAULT_MAX_HEALTH_POINTS
	);
	~Human();

	virtual void logTreatment();

	void applyAbility();

	int getId() const
	{
		return id;
	}

	const std::string & getName() const
	{
		return name;
	}

	int getHealthPoints() const
	{ 
		return healthPoints; 
	}

	void addHealthPoints(int value)
	{ 
		healthPoints = std::min(maxHealthPoints, healthPoints + value); 
	}

	void subHealthPoints(int value)
	{
		healthPoints = std::max(0, healthPoints - value);
	}

	void notifyModel(int id);
};

