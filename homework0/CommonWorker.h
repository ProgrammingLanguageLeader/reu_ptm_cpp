#pragma once

#include <string>
#include <sstream>

#include "AbstractBaseWorker.h"

using namespace std;

class CommonWorker: public AbstractBaseWorker
{
private:
	double salary;

public:
    explicit CommonWorker(const string &, double);
	~CommonWorker();

	void print(ostream & stream) const override;

	friend ostream & operator<<(ostream & stream, CommonWorker const & worker);

	double getSalary() const override {
		return salary;
	}
};
