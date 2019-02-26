#pragma once
#include "IBeverage.h"

class Espresso : public IBeverage
{
public:
	Espresso()
	{
		description = "Small portion of strong coffee";
	}

	double getCost()
	{
		return 150;
	}
};