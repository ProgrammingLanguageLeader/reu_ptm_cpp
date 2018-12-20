#pragma once
#include "ICondimentsDecoratorBase.h"

class SugarCondiment : public ICondimentsDecoratorBase
{
private:
	IBeverage* _beverage;

public:
	SugarCondiment(IBeverage* beverage)
	{
		_beverage = beverage;
		Desctiption = (*_beverage).GetDescription() + " + Sugar";
	}

	double GetCost()
	{
		return (*_beverage).GetCost() + 10;
	}
};