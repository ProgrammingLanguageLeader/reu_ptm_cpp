#pragma once

#include <iostream>

class Money
{
private:
	double value;

public:
	explicit Money(double value = 0) { this->value = value; }

	explicit Money(int rubles, int kopecks = 0) { value = rubles * 100 + kopecks; }

	~Money() = default;

	void setValue(double value) { this->value = value; }

	void setValue(int rubles, int kopecks) { value = rubles * 100 + kopecks; }

	double getValue() const { return value; }

	int getRubles() const { return int(value) / 100; }

	int getKopecks() const { return int(value) % 100; }

	Money & operator+= (const Money & money)
	{
		this->value += money.value;
		return *this;
	}

	Money & operator-= (const Money & money)
	{
		this->value -= money.value;
		return *this;
	}

	template<typename T>
	Money & operator*= (const T & coefficient)
	{
		this->value *= coefficient;
		return *this;
	}

	template<typename T>
	Money & operator/= (const T & coefficient)
	{
		this->value /= coefficient;
		return *this;
	}

	friend Money operator+ (Money leftMoney, Money const & rightMoney)
	{
		leftMoney += rightMoney;
		return leftMoney;
	}

	friend Money operator- (Money leftMoney, Money const & rightMoney)
	{
		leftMoney -= rightMoney;
		return leftMoney;
	}

	template<typename T>
	friend Money operator* (Money leftMoney, const T & coefficient)
	{
		leftMoney *= coefficient;
		return leftMoney;
	}

	template<typename T>
	friend Money operator/ (Money leftMoney, const T & coefficient)
	{
		leftMoney /= coefficient;
		return leftMoney;
	}

	friend Money operator- (Money money)
	{
		money.value = -money.value;
		return money;
	}

	friend bool operator< (const Money & leftMoney, const Money & rightMoney) { return leftMoney.value < rightMoney.value; }
	friend bool operator> (const Money & leftMoney, const Money & rightMoney) { return rightMoney < leftMoney; }
	friend bool operator<= (const Money & leftMoney, const Money & rightMoney) { return !(leftMoney > rightMoney); }
	friend bool operator>= (const Money & leftMoney, const Money & rightMoney) { return !(leftMoney < rightMoney); }

	friend bool operator== (const Money & leftMoney, const Money & rightMoney) { return leftMoney.value == rightMoney.value; }
	friend bool operator!= (const Money & leftMoney, const Money & rightMoney) { return !(leftMoney == rightMoney); }

	friend std::ostream & operator<< (std::ostream & output, const Money & money)
	{
		output << "<rubles = " << money.getRubles() << ", kopecks = " << money.getKopecks() << ">";
		return output;
	}

	friend std::istream & operator>> (std::istream & input, Money & money)
	{
		int rubles, kopecks;
		input >> rubles >> kopecks;
		money.setValue(rubles, kopecks);
		return input;
	}
};
