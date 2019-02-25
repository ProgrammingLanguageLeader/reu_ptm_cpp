#pragma once

#include <string>
#include <exception>
#include <list>
#include <typeinfo>
#include <memory>
#include <chrono>

#include "Car.h"
#include "AbstractBaseWorker.h"
#include "Salesman.h"
#include "CommonWorker.h"

using namespace std;

struct CarNotFoundException : public exception
{
	CarNotFoundException() = default;

    const char* what() const noexcept override {
		return "Car not found";
	}
};

struct WorkerNotFoundException : public exception
{
	WorkerNotFoundException() = default;

    const char* what() const noexcept override {
		return "Worker not found";
	}
};

class CarShowroom
{
private:
	list<shared_ptr<Car>> cars;
	list<shared_ptr<AbstractBaseWorker>> staff;
	double income = 0;
	double losses = 0;

public:
    CarShowroom();
	~CarShowroom();

	void sellCar(shared_ptr<Salesman> salesman, const string & model);

	void addCar(shared_ptr<Car> newCar);

	void addWorker(shared_ptr<AbstractBaseWorker> worker);

	shared_ptr<Car> getCar(int id) const;

	shared_ptr<AbstractBaseWorker> getWorker(int id) const;

	list<shared_ptr<Car>> getSoldCarsListByPeriod(
	        chrono::time_point<chrono::system_clock> periodBegin,
	        chrono::time_point<chrono::system_clock> periodEnd
	        ) const;

	double getIncome() const
	{
		return income;
	}

	double getLosses() const
	{
		return losses;
	}
};
