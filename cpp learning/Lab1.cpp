#include<iostream>
#include "cmplx.h"
#define SIZE 3

using namespace std;

CMPLX AddC(CMPLX a, CMPLX b)
{
	CMPLX n;
	n.Re += a.Re + b.Re;
	n.Im += a.Im + b.Im;
	return n;
}

void Lab1(void)
{
	CMPLX x, y, sum;
	/*CMPLX tab_x[SIZE];
	CMPLX tab_y[SIZE];
	tab_x[0].Init(3, 4);
	tab_x[1].Init(1, 3);
	tab_x[2].Init(5, -2);
	tab_y[0].Init(3, 4);
	tab_y[1].Init(1, 3);
	tab_y[2].Init(5, -2);*/
	//CMPLX tab_z[SIZE];
	double result;
	//int i;
	cout << "Enter first complex number (C1): ";
	x.ReadC();
	cout << "\nEnter second complex number (C2): ";
	y.ReadC();
	cout << "\nYour first complex number is (C1): ";
	x.Print();
	cout << "\nYour second complex number is (C2): ";
	y.Print();
	sum = AddC(x, y);
	cout << "\n\nSum of C1 + C2: ";
	sum.Print();
	result = sum.AbsC();
	cout << "\n\nAbs of C1 + C2: " << result;
}
