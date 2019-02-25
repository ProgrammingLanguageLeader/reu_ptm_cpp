#include "Salesman.h"

Salesman::Salesman(const string & name, double salesPercentToSalary): AbstractBaseWorker(name)
{
	this->salesPercentToSalary = salesPercentToSalary;
}

Salesman::~Salesman() = default;

void Salesman::print(ostream & stream) const
{
	stringstream sstream;
	sstream
		<< "ID: " << id << endl
		<< "Name: " << name << endl
		<< "Sales sum: " << salesSum << endl
		<< "Sales percent to salary: " << salesPercentToSalary << endl;
	stream << sstream.str();
}

double Salesman::getSalary() const
{
	return salesSum * salesPercentToSalary;
}

ostream & operator<<(ostream & stream, Salesman const & salesman)
{
	salesman.print(stream);
	return stream;
}