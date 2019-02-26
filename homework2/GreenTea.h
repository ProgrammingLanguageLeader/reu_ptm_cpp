#pragma once
#include "IBeverage.h"

class GreenTea : public IBeverage
{
public:
	GreenTea()
	{
		description = "Green leaf tea";
	}

	double getCost()
	{
		return 125;
	}
};