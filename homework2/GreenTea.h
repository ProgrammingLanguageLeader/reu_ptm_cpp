#pragma once
#include "IBeverage.h"

class GreenTea : public IBeverage
{
public:
	GreenTea()
	{
		Desctiption = "Green leaf tea";
	}

	double GetCost()
	{
		return 125;
	}
};