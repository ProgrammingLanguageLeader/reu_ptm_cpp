#include <utility>
#include <chrono>

#include "CarShowroom.h"

CarShowroom::CarShowroom() = default;

CarShowroom::~CarShowroom() = default;

void CarShowroom::sellCar(shared_ptr<Salesman> salesman, const string & model)
{
	for (auto & car : cars) {
		if (
			car->getModel() == model &&
			!car->isSold() &&
			!car->isTestDriving()
		)
		{
			car->sell();
			income += car->getSellCost();
			losses += car->getBuyCost();
			salesman->addSalesSum(car->getSellCost());
			return;
		}
	}
	throw CarNotFoundException();
}

void CarShowroom::addCar(shared_ptr<Car> newCar)
{
	cars.push_back(newCar);
}

void CarShowroom::addWorker(shared_ptr<AbstractBaseWorker> worker)
{
	staff.push_back(worker);
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

shared_ptr<AbstractBaseWorker> CarShowroom::getWorker(int id) const
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

list<shared_ptr<Car>> CarShowroom::getSoldCarsListByPeriod(
		chrono::time_point<chrono::system_clock> periodBegin,
		chrono::time_point<chrono::system_clock> periodEnd
		) const
{
	list<shared_ptr<Car>> soldCars = list<shared_ptr<Car>>();
	for (const auto & car : cars)
	{
		if (car->wasSoldInPeriod(periodBegin, periodEnd))
		{
			soldCars.push_back(car);
		}
	}
	return soldCars;
}
