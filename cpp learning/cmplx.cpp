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
	cout << this->Re;
	if(this->Im<0) cout << this->Im << "i";
	else cout << "+" << this->Im << "i";
}

void CMPLX::Init(double a, double b)
{
	this->Re = a;
	this->Im = b;
}

CMPLX CMPLX::AddC(CMPLX a)
{
	CMPLX n;
	n.Re = this->Re + a.Re;
	n.Im = this->Im + a.Im;
	return n;
}

void CMPLX::AddCA(CMPLX* a, CMPLX* b, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		this[i] = a[i].AddC(b[i]);
	}
}

void CMPLX::PrintCarr(int size)
{
	for (int i = 0; i < size; i++)
	{
		this[i].Print();
		cout << " ";
	}
}

double* CMPLX::ArrOfAbs(int size)
{
	double* tab_of_abs = (double*)calloc(size,sizeof(double));
	for (int i = 0; i < size; i++)
	{
		tab_of_abs[i] = this[i].AbsC();
	}
	return tab_of_abs;
}

void CMPLX::PrintTabOfAbs(int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << this->ArrOfAbs(size)[i] << " ";
	}
}

void CMPLX::SwapCMPLX(int idx_1, int idx_2)
{
	CMPLX temp = this[idx_1];
	this[idx_1] = this[idx_2];
	this[idx_2] = temp;
}

void CMPLX::SortArray(int size)
{
	for (int i = 0; i < (size - 1); i++)
	{
		int min_idx = i;

		for (int j = i + 1; j < size; j++)
		{
			if (this[j].AbsC() < this[min_idx].AbsC())
			{
				min_idx = j;
			}
		}

		if (min_idx > i)
		{
			this->SwapCMPLX(i, min_idx);
		}
	}
}