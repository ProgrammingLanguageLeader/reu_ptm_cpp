#pragma once
#include "ICondimentsDecoratorBase.h"

class ChocolateCondiment : public ICondimentsDecoratorBase
{
private:
	IBeverage* _beverage;

public:
	ChocolateCondiment(IBeverage* beverage)
	{
		_beverage = beverage;
		description = (*_beverage).getDescription() + " + Chocolate";
	}

	double getCost()
	{
		return (*_beverage).getCost() + 70;
	}
};
