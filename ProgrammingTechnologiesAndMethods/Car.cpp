#include "Car.h"


int Car::freeId = 1;


Car::Car(double buy_cost, double sell_cost, const string & model, const string & color)
{
	id = freeId++;
	this->buyCost = buy_cost;
	this->sellCost = sell_cost;
	this->model = model;
	this->color = color;
}


Car::~Car()
{
}


void Car::startTestDrive()
{
	if (sold || testDriving) 
	{
		throw CarTestDriveStartException();
	}
	testDriveStartTime = time(NULL);
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
	sellingTime = time(NULL);
	sold = true;
}


bool Car::wasSoldInPeriod(time_t periodBeginTime, time_t periodEndTime) const
{
	return sold && (periodBeginTime <= sellingTime) && (sellingTime <= periodEndTime);
}


ostream & operator<<(ostream & stream, Car const & car) {
	stringstream sstream;
	sstream
		<< "ID: " << car.id << endl
		<< "Model: " << car.model << endl
		<< "Color: " << car.color << endl
		<< "Buy cost: " << car.buyCost << endl
		<< "Sell cost: " << car.sellCost << endl
		<< "Is on test drive? - " << std::boolalpha << car.testDriving << endl;
	if (car.testDriving)
	{
		sstream << "Test drive started at ";
		const std::locale locale = std::locale("");
		std::locale prevLocale = sstream.imbue(locale);
		const auto& timePut = std::use_facet<std::time_put<char>>(locale);
		tm testDriveLocalTime = crossPlatformTime::localtime(car.testDriveStartTime);
		timePut.put(sstream, sstream, ' ', &testDriveLocalTime, 'c');
		sstream.imbue(prevLocale);
		sstream << endl;
	}
	sstream << "Is sold? - " << std::boolalpha << car.sold << endl;
	stream << sstream.str();
	return stream;
}
