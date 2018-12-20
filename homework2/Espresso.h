#pragma once
#include "IBeverage.h"

class Espresso : public IBeverage
{
public:
	Espresso()
	{
		Desctiption = "Small portion of strong coffee";
	}

	double GetCost()
	{
		return 150;
	}
};