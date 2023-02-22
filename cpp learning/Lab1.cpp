#include<iostream>
#include "cmplx.h"
#define SIZE 3

using namespace std;

void Lab1(void)
{
	CMPLX x, y, sum;
	CMPLX tab_x[SIZE];
	CMPLX tab_y[SIZE];
	tab_x[0].Init(3, 4);
	tab_x[1].Init(1, 3);
	tab_x[2].Init(5, -2);
	tab_y[0].Init(3, 4);
	tab_y[1].Init(1, 3);
	tab_y[2].Init(5, -2);
	CMPLX tab_z[SIZE];
	double result;
	cout << "Enter first complex number (C1): ";
	x.ReadC();
	cout << "Enter second complex number (C2): ";
	y.ReadC();
	cout << "Your first complex number is (C1): ";
	x.Print();
	cout << "\nYour second complex number is (C2): ";
	y.Print();
	sum = x.AddC(y);
	cout << "\n\nSum of C1 + C2: ";
	sum.Print();
	result = sum.AbsC();
	cout << "\nAbs of C1 + C2: " << result;
	cout << "\n\nFirst array od complex numbers is (A1): ";
	tab_x->PrintCarr(SIZE);
	cout << "\nSecond array od complex numbers is (A2): ";
	tab_y->PrintCarr(SIZE);
	tab_z->AddCA(tab_x, tab_y, SIZE);
	cout << "\n\nSum of A1 + A2: ";
	tab_z->PrintCarr(SIZE);
	cout << "\nand abs (A1 + A2): ";
	tab_z->PrintTabOfAbs(SIZE);
	cout << "\nSorted array (by abs): ";
	tab_z->SortArray(SIZE);
	tab_z->PrintCarr(SIZE);
	cout << "\nand abs values: ";
	tab_z->PrintTabOfAbs(SIZE);
	cout << "\n\n\n";
}
