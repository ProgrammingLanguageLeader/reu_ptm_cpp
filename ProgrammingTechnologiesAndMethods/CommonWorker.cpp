#include "CommonWorker.h"


CommonWorker::CommonWorker(const string & name, double salary): AbstractWorker(name)
{
	this->salary = salary;
}


CommonWorker::~CommonWorker()
{
}


void CommonWorker::print(ostream & stream) const
{
	stringstream sstream;
	sstream
		<< "ID: " << id << endl
		<< "Name: " << name << endl
		<< "Salary: " << salary << endl;
	stream << sstream.str();
}


ostream & operator<<(ostream & stream, CommonWorker const & worker)
{
	worker.print(stream);
	return stream;
}
