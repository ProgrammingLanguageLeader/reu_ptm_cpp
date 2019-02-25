#include "Car.h"

int Car::freeId = 1;

Car::Car(double buyCost, double sellCost, const string & model)
{
	id = freeId++;
	this->buyCost = buyCost;
	this->sellCost = sellCost;
	this->model = model;
}

Car::~Car() = default;

void Car::startTestDrive()
{
	if (sold || testDriving) 
	{
		throw CarTestDriveStartException();
	}
	testDriveStartTime = system_clock::now();
	testDriving = true;
}

void Car::endTestDrive()
{
	if (sold || !testDriving) 
	{
		throw CarTestDriveEndException();
	}
	testDriving = false;
}

void Car::sell()
{
	if (sold || testDriving)
	{
		throw CarSellingException();
	}
	sellingTime = system_clock::now();
	sold = true;
}

bool Car::wasSoldInPeriod(time_point<system_clock> periodBeginTime, time_point<system_clock> periodEndTime) const
{
	return sold && (periodBeginTime <= sellingTime) && (sellingTime <= periodEndTime);
}

ostream & operator<<(ostream & stream, Car const & car) {
	stringstream sstream;
	sstream
		<< "ID: " << car.id << endl
		<< "Model: " << car.model << endl
		<< "Buy cost: " << car.buyCost << endl
		<< "Sell cost: " << car.sellCost << endl
		<< "Is on test drive? - " << std::boolalpha << car.testDriving << endl;
	if (car.testDriving)
	{
		sstream << "Test drive started at ";
		const time_t cTestDriveStartTime = system_clock::to_time_t(car.testDriveStartTime);
		sstream << std::ctime(&cTestDriveStartTime) << endl;
	}
	sstream << "Is sold? - " << std::boolalpha << car.sold << endl;
	stream << sstream.str();
	return stream;
}
