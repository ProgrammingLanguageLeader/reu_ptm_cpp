#pragma once

#include <string>
#include <sstream>

#include "AbstractWorker.h"


using namespace std;


class CommonWorker: public AbstractWorker
{
private:
	double salary;

public:
	CommonWorker(const string &, double);
	~CommonWorker();

	void print(ostream & stream) const;

	friend ostream & operator<<(ostream & stream, CommonWorker const & worker);

	double getSalary() const
	{
		return salary;
	}
};

