#pragma once

#include <string>


using namespace std;


class AbstractWorker
{
protected:
	static int freeId;
	int id;
	string name = "";

public:
	AbstractWorker();
	AbstractWorker(const string &);
	~AbstractWorker();

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