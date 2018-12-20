#include "AbstractWorker.h"

int AbstractWorker::freeId = 1;


AbstractWorker::AbstractWorker()
{
	id = freeId++;
}


AbstractWorker::~AbstractWorker()
{
}


AbstractWorker::AbstractWorker(const string & name)
{
	id = freeId++;
	this->name = name;
}
