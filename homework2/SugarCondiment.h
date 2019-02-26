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
		description = (*_beverage).getDescription() + " + Sugar";
	}

	double getCost()
	{
		return (*_beverage).getCost() + 10;
	}
};