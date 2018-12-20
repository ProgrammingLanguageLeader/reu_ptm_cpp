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
		Desctiption = (*_beverage).GetDescription() + " + Milk";
	}

	double GetCost()
	{
		return (*_beverage).GetCost() + 50;
	}
};