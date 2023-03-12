#include "FloatNumber.h"
#include <cmath>
#include <iostream>
using namespace std;

FloatNumber::FloatNumber(float f)
{
	this->integerValue = floor(f);
	this->decimalValue = (f - floor(f))*1000;
}

FloatNumber::FloatNumber(string b)
{
	string i = b.substr(0, b.find('.'));
	this->integerValue = stoi(i);
	string d = b.substr(b.find('.') + 1, b.length() - (b.find('.') + 1));
	this->decimalValue = stoi(d);
}

void FloatNumber::WriteToConsole()
{
	if (this->integerValue < 100) cout << ' ';
	if (this->integerValue < 10) cout << ' ';
	cout << this->integerValue << '.';
	if (this->decimalValue < 100) cout << '0';
	if (this->decimalValue < 10) cout << '0';
	cout << this->decimalValue;
}

void FloatNumber::ReadFromConsole()
{
	bool iscorrect = false;
	int i, d;
	while (!iscorrect)
	{
		cout << "Provide Integer Value: ";
		cin >> i;
		cout << "Provide Decimal Value: ";
		cin >> d;
		if (i > 0 && d > 0 && d < MAX_DECIMAL_VALUE)
		{
			this->integerValue = i;
			this->decimalValue = d;
			iscorrect = true;
		}
		else cout << "Wrong input!" << endl;
	}
}

bool FloatNumber::Equals(const FloatNumber& other) const
{
	if (this->decimalValue == other.decimalValue && this->integerValue == other.integerValue) return true;
	return false;
}

FloatNumber::FloatNumber(int i, int d)
{
	this->integerValue = i;
	this->decimalValue = d;
}

FloatNumber operator+(const FloatNumber& floatA, const FloatNumber& floatB)
{
	FloatNumber sum;
	sum.integerValue = floatA.integerValue + floatB.integerValue;
	sum.decimalValue = floatA.decimalValue + floatB.decimalValue;
	if (sum.decimalValue >= MAX_DECIMAL_VALUE)
	{
		sum.integerValue++;
		sum.decimalValue -= MAX_DECIMAL_VALUE;
	}
	return sum;
}