#include <iostream>
#include <iomanip>
#include <memory>

#include "Car.h"
#include "CarShowroom.h"


using namespace std;


enum Commands {
	ADD_CAR = 1,
	ADD_STUFF,
	SELL_CAR,
	GET_SALARY,
	PRINT_SOLD_CARS,
	START_TEST_DRIVE,
	END_TEST_DRIVE,
	EXIT,
};


int main()
{
	CarShowroom showroom("My showroom");
	bool quit = false;
	while (!quit)
	{
		cout 
			<< "Enter a command number" << endl
			<< "(" << ADD_CAR << " - add car)" << endl
			<< "(" << ADD_STUFF << " - add stuff)" << endl
			<< "(" << SELL_CAR << " - sell car)" << endl
			<< "(" << GET_SALARY << " - get salary)" << endl
			<< "(" << PRINT_SOLD_CARS << " - print sold cars" << endl
			<< "(" << START_TEST_DRIVE << " - start test drive)" << endl
			<< "(" << END_TEST_DRIVE << " - end test drive)" << endl
			<< "(" << EXIT << " and more - exit)" << endl
			<< "Command: ";
		int command;
		cin >> command;

		switch (command)
		{
			case ADD_CAR: 
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
				break;
			}

			case ADD_STUFF:
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
				break;
			}

			case SELL_CAR:
			{
				cout << "Choose salesman by ID" << endl;
				int salesmanId;
				cout << "Enter ID: ";
				cin >> salesmanId;
				try
				{
					auto workerById = showroom.getWorker(salesmanId);
					Salesman& salesman = dynamic_cast<Salesman&>(*workerById);

					cout << "Choose car by model and color" << endl;
					string model, color;
					cout << "Model: ";
					cin >> model;
					cout << "Color: ";
					cin >> color;
					showroom.sellCar(salesman, model, color);
					cout << "OK" << endl << endl;
				}
				catch (bad_cast ex)
				{
					cout << "The worker is not a salesman" << endl << endl;
					break;
				}
				catch (WorkerNotFoundException ex)
				{
					cout << ex.what() << endl << endl;
					break;
				}
				catch (CarNotFoundException ex)
				{
					cout << ex.what() << endl << endl;
					break;
				}
				break;
			}

			case GET_SALARY:
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
					break;
				}
				break;
			}

			case PRINT_SOLD_CARS:
			{
				struct tm periodStart = { 0 }, periodEnd = { 0 };
				cout << "Enter the period start (%d-%m-%Y): ";
				cin >> std::get_time(&periodStart, "%d-%m-%Y");
				cout << "Enter the period end (%d-%m-%Y): ";
				cin >> std::get_time(&periodEnd, "%d-%m-%Y");
				shared_ptr<list<Car>> soldCars = showroom.getSoldCarsListByPeriod(periodStart, periodEnd);
				if (soldCars->size() == 0)
				{
					cout << "No sold cars at this period" << endl << endl;
					break;
				}
				cout << "Sold cars by the period:" << endl;
				for (Car car : *soldCars)
				{
					cout << car << endl;
				}
				cout << "OK" << endl << endl;
				break;
			}

			case START_TEST_DRIVE:
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
					break;
				}
				catch (CarTestDriveStartException ex)
				{
					cout << ex.what() << endl << endl;
					break;
				}
				break;
			}

			case END_TEST_DRIVE:
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
					break;
				}
				catch (CarTestDriveEndException ex)
				{
					cout << ex.what() << endl << endl;
					break;
				}
				break;
			}

			default:
			{
				quit = true;
				break;
			}
		}
	}
	
	return 0;
}