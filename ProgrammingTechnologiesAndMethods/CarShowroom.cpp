#include "CarShowroom.h"


CarShowroom::CarShowroom(string name)
{
	this->name = name;
}


CarShowroom::~CarShowroom()
{
}


void CarShowroom::sellCar(Salesman& salesman, const string & model)
{
	for (auto iter = cars.begin(); iter != cars.end(); iter++)
	{
		auto carPointer = *iter;
		if (
			carPointer->getModel() == model && 
			!carPointer->isSold() && 
			!carPointer->isTestDriving()
		)
		{
			carPointer->sell();
			salesman.addSalesSum(carPointer->getSellCost());
			return;
		}
	}
	throw CarNotFoundException();
}


void CarShowroom::sellCar(Salesman& salesman, const string & model, const string & color)
{
	for (auto iter = cars.begin(); iter != cars.end(); iter++)
	{
		auto carPointer = *iter;
		if (
			carPointer->getModel() == model &&
			carPointer->getColor() == color &&
			!carPointer->isSold() &&
			!carPointer->isTestDriving()
		)
		{
			carPointer->sell();
			salesman.addSalesSum(carPointer->getSellCost());
			return;
		}
	}
	throw CarNotFoundException();
}


void CarShowroom::sellCar(Salesman& salesman, int id)
{
	for (auto iter = cars.begin(); iter != cars.end(); iter++)
	{
		auto carPointer = *iter;
		if (
			carPointer->getId() == id && 
			!carPointer->isSold() && 
			!carPointer->isTestDriving()
		)
		{
			carPointer->sell();
			salesman.addSalesSum(carPointer->getSellCost());
			return;
		}
	}
	throw CarNotFoundException();
}


void CarShowroom::addCar(shared_ptr<Car> newCar)
{
	cars.push_back(newCar);
}


void CarShowroom::addWorker(shared_ptr<AbstractWorker> worker)
{
	staff.push_back(worker);
}


shared_ptr<list<Salesman>> CarShowroom::getSalesmanList() const
{
	auto salesmansList = make_shared<list<Salesman>>();
	for (auto worker : staff)
	{
		if (typeid(*worker) == typeid(Salesman))
		{
			Salesman salesman = dynamic_cast<Salesman&>(*worker);
			salesmansList->push_back(salesman);
		}
	}
	return salesmansList;
}


shared_ptr<Car> CarShowroom::getCar(int id) const
{
	for (auto carPointer : cars)
	{
		if (carPointer->getId() == id)
		{
			return carPointer;
		}
	}
	throw CarNotFoundException();
}


shared_ptr<AbstractWorker> CarShowroom::getWorker(const string & name) const
{
	for (auto workerPointer : staff)
	{
		if (workerPointer->getName() == name)
		{
			return workerPointer;
		}
	}
	throw WorkerNotFoundException();
}


shared_ptr<AbstractWorker> CarShowroom::getWorker(int id) const
{
	for (auto workerPointer : staff)
	{
		if (workerPointer->getId() == id)
		{
			return workerPointer;
		}
	}
	throw WorkerNotFoundException();
}


shared_ptr<list<Car>> CarShowroom::getSoldCarsListByPeriod(tm& periodBegin, tm& periodEnd) const
{
	time_t periodBeginTime = mktime(&periodBegin);
	time_t periodEndTime = mktime(&periodEnd);
	shared_ptr<list<Car>> soldCars = make_shared<list<Car>>();
	for (auto carPointer : cars)
	{
		if (carPointer->wasSoldInPeriod(periodBeginTime, periodEndTime))
		{
			soldCars->push_back(*carPointer);
		}
	}
	return soldCars;
}
