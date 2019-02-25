#include <utility>

#pragma once

#include <string>
#include <ctime>
#include <exception>
#include <locale>
#include <sstream>
#include <chrono>
#include <iomanip>

using std::string;
using std::exception;
using std::ostream;
using std::endl;
using std::stringstream;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::put_time;
using std::localtime;

struct CarTestDriveStartException : public exception
{
	CarTestDriveStartException() = default;

	const char* what() const noexcept override {
		return "Car test drive start error";
	}
};

struct CarTestDriveEndException : public exception
{
	CarTestDriveEndException() = default;

	const char* what() const noexcept override {
		return "Car test drive end error";
	}
};

struct CarSellingException : public exception
{
	CarSellingException() = default;

	const char* what() const noexcept override {
		return "Car selling error";
	}
};

class Car
{
private:
	static int freeId;
	int id;
	string model;
	double buyCost;
	double sellCost;
	bool testDriving = false;
	bool sold = false;
	time_point<system_clock> testDriveStartTime;
    time_point<system_clock> sellingTime;

public:
	Car(double buyCost, double sellCost, const string & model);
	~Car();

	friend ostream & operator<<(ostream & stream, Car const & car);

	int getId() const
	{
		return id;
	}

	void setModel(string newModel)
	{
		model = std::move(newModel);
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

	bool wasSoldInPeriod(time_point<system_clock> periodBeginTime, time_point<system_clock> periodEndTime) const;
};