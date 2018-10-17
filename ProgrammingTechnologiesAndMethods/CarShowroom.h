#pragma once

#include <string>
#include <exception>
#include <list>
#include <typeinfo>
#include <memory>

#include "Car.h"
#include "AbstractWorker.h"
#include "Salesman.h"
#include "CommonWorker.h"


using namespace std;


struct CarNotFoundException : public exception
{
	CarNotFoundException() {};

	virtual const char* what() const throw()
	{
		return "Car not found";
	}
};


struct WorkerNotFoundException : public exception
{
	WorkerNotFoundException() {}

	virtual const char* what() const throw()
	{
		return "Worker not found";
	}
};


class CarShowroom
{
private:
	string name;
	list<shared_ptr<Car>> cars;
	list<shared_ptr<AbstractWorker>> staff;
	double income = 0;
	double losses = 0;

public:
	CarShowroom(string name);
	~CarShowroom();

	void sellCar(Salesman& salesman, const string & model);
	void sellCar(Salesman& salesman, const string & model, const string & color);
	void sellCar(Salesman& salesman, int id);

	void addCar(shared_ptr<Car> newCar);

	void addWorker(shared_ptr<AbstractWorker> worker);

	shared_ptr<list<Salesman>> getSalesmanList() const;

	shared_ptr<Car> getCar(int id) const;

	shared_ptr<AbstractWorker> getWorker(const string & name) const;
	shared_ptr<AbstractWorker> getWorker(int id) const;

	shared_ptr<list<Car>> getSoldCarsListByPeriod(tm& periodBegin, tm& periodEnd) const;

	const string & getName() const
	{
		return name;
	}

	double getIncome() const
	{
		return income;
	}

	double getLosses() const
	{
		return losses;
	}
};

