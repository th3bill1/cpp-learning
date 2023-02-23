#include<iostream>
#include "cmplx.h"

using namespace std;

void Lab1(void)
{
	const int size = 3;
	cout.precision(3);
	CMPLX x, y, sum;
	CMPLX tab_x[size] = { NULL };
	CMPLX tab_y[size] = { NULL };
	tab_x[0].Init(3, 4);
	tab_x[1].Init(1, 3);
	tab_x[2].Init(5, -2);
	tab_y[0].Init(3, 4);
	tab_y[1].Init(1, 3);
	tab_y[2].Init(5, -2);
	CMPLX tab_z[size];
	double result;
	cout << "Enter first complex number (C1): ";
	x.ReadC();
	cout << "Enter second complex number (C2): ";
	y.ReadC();
	cout << "Your first complex number is (C1): ";
	x.Print();
	cout << endl << "Your second complex number is (C2): ";
	y.Print();
	sum = x.AddC(y);
	cout << endl << endl << "Sum of C1 + C2: ";
	sum.Print();
	result = sum.AbsC();
	cout << endl << "Abs of C1 + C2: " << result;
	cout << endl << endl << "First array od complex numbers is (A1): ";
	tab_x->PrintCarr(size);
	cout << endl << "Second array od complex numbers is (A2): ";
	tab_y->PrintCarr(size);
	tab_z->AddCA(tab_x, tab_y, size);
	cout << endl << endl << "Sum of A1 + A2: ";
	tab_z->PrintCarr(size);
	cout << endl << "and abs (A1 + A2): ";
	tab_z->PrintTabOfAbs(size);
	cout << endl << "Sorted array (by abs): ";
	tab_z->SortArray(size);
	tab_z->PrintCarr(size);
	cout << endl << "and abs values: ";
	tab_z->PrintTabOfAbs(size);
	cout << endl << endl << endl;
}
