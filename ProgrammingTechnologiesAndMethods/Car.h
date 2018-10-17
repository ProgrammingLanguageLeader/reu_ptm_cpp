#pragma once

#include <string>
#include <ctime>
#include <exception>
#include <locale>
#include <sstream>

#include "localtime.h"


using std::string;
using std::exception;
using std::ostream;
using std::endl;
using std::stringstream;


struct CarTestDriveStartException : public exception
{
	CarTestDriveStartException() {};

	virtual const char* what() const throw()
	{
		return "Car test drive start error";
	}
};


struct CarTestDriveEndException : public exception
{
	CarTestDriveEndException() {};

	virtual const char* what() const throw()
	{
		return "Car test drive end error";
	}
};

struct CarSellingException : public exception
{
	CarSellingException() {};

	virtual const char* what() const throw()
	{
		return "Car selling error";
	}
};


class Car
{
private:
	static int freeId;
	int id;
	string model;
	string color;
	double buyCost;
	double sellCost;
	bool testDriving = false;
	bool sold = false;
	time_t testDriveStartTime = 0;
	time_t sellingTime = 0;

public:
	Car(double, double, const string &, const string & = "black");
	~Car();

	friend ostream & operator<<(ostream & stream, Car const & car);

	int getId() const
	{
		return id;
	}

	const string & getColor() const
	{
		return color;
	}

	void setModel(string newModel)
	{
		model = newModel;
	}

	double getBuyCost() const
	{
		return buyCost;
	}

	double getSellCost() const
	{
		return sellCost;
	}

	const string & getModel() const
	{
		return model;
	}

	bool isSold() const
	{
		return sold;
	}

	bool isTestDriving() const
	{
		return testDriving;
	}

	void startTestDrive();
	void endTestDrive();
	void sell();

	bool wasSoldInPeriod(time_t periodBeginTime, time_t periodEndTime) const;
};