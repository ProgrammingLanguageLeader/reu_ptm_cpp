#pragma once
#include "ICondimentsDecoratorBase.h"

class MilkCondiment : public ICondimentsDecoratorBase
{
private:
	IBeverage* _beverage;

public:
	MilkCondiment(IBeverage* beverage)
	{
		_beverage = beverage;
		description = (*_beverage).getDescription() + " + Milk";
	}

	double getCost()
	{
		return (*_beverage).getCost() + 50;
	}
};