#pragma once
#include "IBeverage.h"

class BlackTea : public IBeverage
{
public:
	BlackTea()
	{
		description = "Black tea from teabag";
	}

	double getCost()
	{
		return 25;
	}
};
