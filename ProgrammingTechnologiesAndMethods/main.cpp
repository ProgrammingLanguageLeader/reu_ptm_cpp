#include <iostream>
#include <iomanip>
#include <memory>

#include "Car.h"
#include "CarShowroom.h"


using namespace std;


enum Commands {
	INIT = 0,
	ADD_CAR,
	ADD_WORKER,
	SELL_CAR,
	GET_SALARY,
	PRINT_SOLD_CARS,
	START_TEST_DRIVE,
	END_TEST_DRIVE,
	GET_REAL_INCOME,
	EXIT,
};


void initShowroom(CarShowroom& showroom)
{
	showroom.addCar(make_shared<Car>(100000, 110000, "Audi", "black"));
	showroom.addCar(make_shared<Car>(110000, 120000, "Audi", "green"));
	showroom.addCar(make_shared<Car>(100000, 110000, "Audi", "red"));

	showroom.addWorker(make_shared<Salesman>("Vasya"));
	showroom.addWorker(make_shared<CommonWorker>("Vasya", 1000));

	cout << "OK" << endl << endl;
}


void addCar(CarShowroom& showroom)
{
	string model;
	int buyCost;
	int sellCost;

	cout << "Model: ";
	cin >> model;
	cout << "Buy cost: ";
	cin >> buyCost;
	cout << "Sell cost: ";
	cin >> sellCost;
	showroom.addCar(make_shared<Car>(buyCost, sellCost, model));
	cout << "OK" << endl << endl;
}


void addWorker(CarShowroom& showroom)
{
	string input;
	bool addSalesman = false;
	bool addCommonWorker = false;
	while (!addSalesman && !addCommonWorker)
	{
		cout << "Whom do you want to add: worker(w) or salesman(s): ";
		cin >> input;
		addCommonWorker = input == "w";
		addSalesman = input == "s";
	}
	string name;
	cout << "Enter a person's name: ";
	cin >> name;
	if (addSalesman)
	{
		showroom.addWorker(make_shared<Salesman>(name));
	}
	else
	{
		double salary;
		cout << "Enter salary: ";
		cin >> salary;
		showroom.addWorker(make_shared<CommonWorker>(name, salary));
	}
	cout << "OK" << endl << endl;
}


void sellCar(CarShowroom& showroom)
{
	cout << "Choose salesman by ID" << endl;
	int salesmanId;
	cout << "Enter ID: ";
	cin >> salesmanId;
	try
	{
		auto workerById = showroom.getWorker(salesmanId);
		Salesman& salesman = dynamic_cast<Salesman&>(*workerById);

		cout << "Choose car by model" << endl;
		string model;
		cout << "Model: ";
		cin >> model;
		showroom.sellCar(salesman, model);
		cout << "OK" << endl << endl;
	}
	catch (bad_cast ex)
	{
		cout << "The worker is not a salesman" << endl << endl;
		return;
	}
	catch (WorkerNotFoundException ex)
	{
		cout << ex.what() << endl << endl;
		return;
	}
	catch (CarNotFoundException ex)
	{
		cout << ex.what() << endl << endl;
		return;
	}
}


void getSalary(CarShowroom& showroom)
{
	int workerId;
	cout << "Enter a worker's ID: ";
	cin >> workerId;
	try
	{
		auto worker = showroom.getWorker(workerId);
		cout << "Salary = " << worker->getSalary() << endl;
		cout << "OK" << endl << endl;
	}
	catch (WorkerNotFoundException ex)
	{
		cout << ex.what() << endl << endl;
		return;
	}
}


void printSoldCars(CarShowroom& showroom)
{
	int workerId;
	cout << "Enter a worker's ID: ";
	cin >> workerId;
	try
	{
		auto worker = showroom.getWorker(workerId);
		cout << "Salary = " << worker->getSalary() << endl;
		cout << "OK" << endl << endl;
	}
	catch (WorkerNotFoundException ex)
	{
		cout << ex.what() << endl << endl;
		return;
	}
}


void startTestDrive(CarShowroom& showroom)
{
	int carId;
	cout << "Enter the car's ID: ";
	cin >> carId;
	try
	{
		auto carPointer = showroom.getCar(carId);
		carPointer->startTestDrive();
		cout << "OK" << endl << endl;
	}
	catch (CarNotFoundException ex)
	{
		cout << ex.what() << endl << endl;
		return;
	}
	catch (CarTestDriveStartException ex)
	{
		cout << ex.what() << endl << endl;
		return;
	}
}


void endTestDrive(CarShowroom& showroom)
{
	int carId;
	cout << "Enter the car's ID: ";
	cin >> carId;
	try
	{
		auto carPointer = showroom.getCar(carId);
		carPointer->endTestDrive();
		cout << "OK" << endl << endl;
	}
	catch (CarNotFoundException ex)
	{
		cout << ex.what() << endl << endl;
		return;
	}
	catch (CarTestDriveEndException ex)
	{
		cout << ex.what() << endl << endl;
		return;
	}
}


void getRealIncome(CarShowroom& showroom)
{
	cout << "Real income = " << showroom.getIncome() - showroom.getLosses() << endl << endl;
}


int main()
{
	CarShowroom showroom("My showroom");
	bool quit = false;
	while (!quit)
	{
		cout 
			<< "Enter a command number" << endl
			<< "(" << INIT << " - init showroom)" << endl
			<< "(" << ADD_CAR << " - add car)" << endl
			<< "(" << ADD_WORKER << " - add worker)" << endl
			<< "(" << SELL_CAR << " - sell car)" << endl
			<< "(" << GET_SALARY << " - get salary)" << endl
			<< "(" << PRINT_SOLD_CARS << " - print sold cars" << endl
			<< "(" << START_TEST_DRIVE << " - start test drive)" << endl
			<< "(" << END_TEST_DRIVE << " - end test drive)" << endl
			<< "(" << GET_REAL_INCOME << " - get a real income of the showroom)" << endl
			<< "(" << EXIT << " and more - exit)" << endl
			<< "Command: ";
		int command;
		cin >> command;

		switch (command)
		{
			case INIT:
				initShowroom(showroom);
				break;

			case ADD_CAR: 
				addCar(showroom);
				break;

			case ADD_WORKER:
				addWorker(showroom);
				break;

			case SELL_CAR:
				sellCar(showroom);
				break;

			case GET_SALARY:
				getSalary(showroom);
				break;

			case PRINT_SOLD_CARS:
				printSoldCars(showroom);
				break;

			case START_TEST_DRIVE:
				startTestDrive(showroom);
				break;

			case END_TEST_DRIVE:
				endTestDrive(showroom);
				break;

			case GET_REAL_INCOME:
				getRealIncome(showroom);
				break;

			default:
			{
				quit = true;
				break;
			}
		}
	}
	
	return 0;
}