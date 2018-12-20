#pragma once
#include "IBeverage.h"

class BlackTea : public IBeverage
{
public:
	BlackTea()
	{
		Desctiption = "Black tea from teabag";
	}

	double GetCost()
	{
		return 25;
	}
};
