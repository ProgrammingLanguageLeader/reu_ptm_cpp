#pragma once
#include <string>

using namespace std;

class IBeverage
{
protected:
	string description = "";

public:
	string getDescription()
	{
		return description;
	}

	virtual double getCost() = 0;
};