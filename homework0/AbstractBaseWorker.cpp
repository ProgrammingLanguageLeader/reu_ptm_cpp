#include <sstream>

#include "AbstractBaseWorker.h"

int AbstractBaseWorker::freeId = 1;

AbstractBaseWorker::AbstractBaseWorker()
{
	id = freeId++;
}

AbstractBaseWorker::~AbstractBaseWorker() = default;

AbstractBaseWorker::AbstractBaseWorker(const string & name)
{
	id = freeId++;
	this->name = name;
}
