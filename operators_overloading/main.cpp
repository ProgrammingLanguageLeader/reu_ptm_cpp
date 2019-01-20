#include <iostream>

#include "Money.h"

int main(int argc, char* argv[])
{
	const int multiplicationCoefficient = 3;
	const double divisionCoefficient = 6;

	// takes an input for the first Money object as double value and prints it
	std::cout << "Taking input for the second Money object..." << std::endl;
	double value;
	std::cout << "(double) value: ";
	std::cin >> value;
	Money firstMoney = Money(value);
	std::cout << firstMoney << std::endl;
	std::cout << "Done." << std::endl << std::endl;

	// takes an input for the second Money object as 2 integers (rubles and kopecks) and prints it
	std::cout << "Taking input for the second Money object..." << std::endl;
	int rubles, kopecks;
	std::cout << "(int) rubles: ";
	std::cin >> rubles;
	std::cout << "(int) kopecks: ";
	std::cin >> kopecks;
	Money secondMoney = Money(rubles, kopecks);
	std::cout << secondMoney << std::endl;
	std::cout << "Done." << std::endl << std::endl;

	// does arithmetics operations on the first and the second Money objects and prints results
	std::cout << "Doing some arithmetics..." << std::endl;
	std::cout
		<< "Addition: " << std::endl
		<< firstMoney << " + " << secondMoney << " = " << firstMoney + secondMoney << std::endl
		<< std::endl
		<< "Subtraction: " << std::endl
		<< firstMoney << " - " << secondMoney << " = " << firstMoney - secondMoney << std::endl
		<< std::endl
		<< "Multiplication: " << std::endl
		<< firstMoney << " * " << multiplicationCoefficient << " = " << firstMoney * multiplicationCoefficient << std::endl
		<< secondMoney << " * " << multiplicationCoefficient << " = " << secondMoney * multiplicationCoefficient << std::endl
		<< std::endl
		<< "Division: " << std::endl
		<< firstMoney << " / " << divisionCoefficient << " = " << firstMoney / divisionCoefficient << std::endl
		<< secondMoney << " / " << divisionCoefficient << " = " << secondMoney / divisionCoefficient << std::endl
		<< std::endl
		<< "Sign changing: " << std::endl
		<< "-" << firstMoney << " = " << -firstMoney << std::endl
		<< "-" << secondMoney << " = " << -secondMoney << std::endl;
	std::cout << "Done." << std::endl << std::endl;

	// does comparisons on the first and the second Money objects and prints results
	std::cout << "Doing some comparisons..." << std::endl;
	std::cout
		<< firstMoney << " < " << secondMoney << " is " << (firstMoney < secondMoney ? "true" : "false") << std::endl
		<< firstMoney << " <= " << secondMoney << " is " << (firstMoney <= secondMoney ? "true" : "false") << std::endl
		<< firstMoney << " > " << secondMoney << " is " << (firstMoney > secondMoney ? "true" : "false") << std::endl
		<< firstMoney << " >= " << secondMoney << " is " << (firstMoney >= secondMoney ? "true" : "false") << std::endl
		<< firstMoney << " == " << secondMoney << " is " << (firstMoney == secondMoney ? "true" : "false") << std::endl
		<< firstMoney << " != " << secondMoney << " is " << (firstMoney != secondMoney ? "true" : "false") << std::endl;
	std::cout << "Done." << std::endl << std::endl;
}