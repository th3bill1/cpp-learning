#include <iostream>
using namespace std;
#include "fraction.h"

Fraction::Fraction()
{
	numerator = 1;
	denominator = 1;
}

Fraction::Fraction(int n, int d)
{
	numerator = n;
	denominator = d;
	this->Shorten();
}

void Fraction::read()
{
	cout << endl << "Enter numerator:";
	cin >> this->numerator;
	cout << "Enter denominator:";
	cin >> this->denominator;
	this->Shorten();
}

void Fraction::write()
{
	cout << this->numerator << "/" << this->denominator;
}

Fraction add(Fraction arg1, Fraction arg2)
{
	Fraction n = { arg1.GetNum() * arg2.GetDen() + arg1.GetDen() * arg2.GetNum(), arg1.GetDen() * arg2.GetDen()};
	n.Shorten();
	return n;
}

ostream& operator<<(ostream& os, Fraction u)
{
	os << endl << u.GetNum() << "/" << u.GetDen();
	return os;
}
istream& operator>>(istream& in, Fraction& u)
{
	int n, d;
	cout << endl << "Enter numerator:";
	in >> n;
	cout << "Enter denominator:";
	in >> d;
	u.SetNum(n);
	u.SetDen(d);
	u.Shorten();
	return in;
}

int Fraction::GetNum()
{
	return this->numerator;
}
int Fraction::GetDen()
{
	return this->denominator;
}

void Fraction::SetNum(int n)
{
	this->numerator = n;
}
void Fraction::SetDen(int d)
{
	this->denominator = d;
}

int gcd(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;	
	}
	return a;
}

void Fraction::Shorten()
{
	int gcd_ = gcd(this->numerator, this->denominator);
	this->numerator = this->numerator / (gcd_);
	this->denominator = this->denominator / (gcd_);
}