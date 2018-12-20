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
		Desctiption = (*_beverage).GetDescription() + " + Chocolate";
	}

	double GetCost()
	{
		return (*_beverage).GetCost() + 70;
	}
};
