#pragma once

#include <string>

using namespace std;

class AbstractBaseWorker
{
protected:
	static int freeId;
	int id;
	string name = "";

public:
	AbstractBaseWorker();
	explicit AbstractBaseWorker(const string &);
	~AbstractBaseWorker();

	virtual void print(ostream & stream) const = 0;

	virtual double getSalary() const = 0;

	int getId() const
	{ 
		return id; 
	};
	
	const string & getName() const
	{ 
		return name; 
	}
};