#pragma once

#include <string>
#include <sstream>

#include "AbstractWorker.h"


using namespace std;


class Salesman: public AbstractWorker
{
private:
	double salesSum = 0;
	double salesPercentToSalary;

public:
	Salesman(const string &, double = 0.02);
	~Salesman();

	void print(ostream & stream) const;

	double getSalary() const;

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

