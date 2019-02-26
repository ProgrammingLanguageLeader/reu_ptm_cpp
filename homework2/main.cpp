#include <iostream>
#include <string>

#include "IBeverage.h"
#include "Espresso.h"
#include "BlackTea.h"
#include "GreenTea.h"
#include "SugarCondiment.h"
#include "MilkCondiment.h"
#include "ChocolateCondiment.h"

using namespace std;

void printBeverage(IBeverage* beverage)
{
	cout << "Beverage: " << beverage->getDescription() << " | Cost: " << beverage->getCost() << endl;
}

int main()
{
	IBeverage* espresso = new Espresso();
	IBeverage* blackTea = new BlackTea();
	IBeverage* greenTea = new GreenTea();

	printBeverage(espresso);
	printBeverage(blackTea);
	printBeverage(greenTea);

	cout << "------------------------------------------------------------------" << endl;

	IBeverage* capuccino = (IBeverage*) new SugarCondiment(
		(IBeverage*) new MilkCondiment(
			new Espresso()
		)
	);
	printBeverage(capuccino);

	IBeverage* greenTeaWithSugar = (IBeverage*) new SugarCondiment(
		new GreenTea()
	);
	printBeverage(greenTeaWithSugar);

	return 0;
}