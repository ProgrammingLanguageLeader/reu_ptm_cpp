#pragma once

#include <string>
#include <sstream>

#include "AbstractBaseWorker.h"

using namespace std;

class Salesman: public AbstractBaseWorker
{
private:
	double salesSum = 0;
	double salesPercentToSalary;

public:
	explicit Salesman(const string &, double = 0.02);
	~Salesman();

	void print(ostream & stream) const override;

	double getSalary() const override;

	friend ostream & operator<<(ostream & stream, Salesman const & salesman);

	double getSalesSum()
	{
		return salesSum;
	}

	void addSalesSum(double sum)
	{
		salesSum += sum;
	}
};

