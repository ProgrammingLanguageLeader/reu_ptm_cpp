#pragma once
#include <string>
using namespace std;

class IBeverage
{
protected:
	string Desctiption = "";

public:
	string GetDescription()
	{
		return Desctiption;
	}

	virtual double GetCost() = 0;
};