#include<stdio.h>
#include<math.h>
#include<iostream>
#include "cmplx.h"
#define pow(a) (a*a)
using namespace std;

void CMPLX::ReadC()
{
	cin >> this->Re;
	cin >> this->Im;
}

double CMPLX::AbsC()
{
	return sqrt(pow(this->Re) + pow(this->Im));
}

void CMPLX::Print()
{
	cout << this->Re << "+" << this->Im << "i";
}

void CMPLX::Init(double a, double b)
{
	this->Re = a;
	this->Im = b;
}

void CMPLX::AddCA(CMPLX* a, CMPLX* b, CMPLX* c, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		//c[i] = AddC(a[i], b[i]);
		//c[i].Re = a[i].Re + b[i].Re;
		//c[i].Im = a[i].Im + b[i].Im;
	}
}