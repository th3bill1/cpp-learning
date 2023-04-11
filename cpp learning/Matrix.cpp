#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int rows_count, int columns_count)
{
	if (rows_count > 0 && columns_count > 0)
	{
		this->columns_count = columns_count;
		this->rows_count = rows_count;
		this->rows = new Vector * [rows_count];
		for (int i = 0; i < this->rows_count; i++)
		{
			this->rows[i] = new Vector(this->columns_count);
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->rows_count; i++)
	{
		delete this->rows[i];
	}
	if (this->rows != nullptr) delete[] this->rows;
}

int Matrix::operator()(int i, int j) const
{
	Vector v = *this->rows[i];
	return v(j);
}

int& Matrix::operator()(int i, int j)
{
	return this->rows[i]->operator()(j);
}

Matrix::Matrix(const Matrix& matrix)
{
	this->rows_count = matrix.rows_count;
	this->rows = new Vector* [rows_count];
	for (int i = 0; i < this->rows_count; i++)
	{
		this->rows[i] = new Vector(*matrix.rows[i]);
	}
}

Matrix& Matrix::operator=(const Matrix& matrix)
{
	for (int i = 0; i < this->rows_count; i++)
	{
		delete this->rows[i];
	}
	if (this->rows != nullptr) delete[] this->rows;
	this->rows_count = matrix.rows_count;
	this->rows = new Vector*[rows_count];
	for (int i = 0; i < this->rows_count; i++)
	{
		this->rows[i] = new Vector(*matrix.rows[i]);
	}
	return *this;
}

Matrix& Matrix::operator--()
{
	if (this->rows_count > 1)
	{
		Vector** p = this->rows;
		this->rows = new Vector * [--this->rows_count];
		for (int i = 0; i < this->rows_count; i++)
		{
			this->rows[i] = new Vector(*p[i]);
		}
		for (int i = 0; i < this->rows_count; i++)
		{
			delete p[i];
		}
		delete[] p;
	}
	else if (this->rows_count-- == 1) delete[] this->rows;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
	os << "[\n";
	for (int i = 0; i < matrix.rows_count; i++)
	{
		os << *matrix.rows[i] << "\n";
	}
	os << "]\n";
	return os;
}

Matrix* operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix* p = new Matrix(lhs.rows_count, rhs.columns_count);
	for (int i = 0; i < p->rows_count; i++)
	{
		for (int j = 0; j < p->columns_count; j++)
		{
			p->operator()(i,j) = CellValue(lhs, rhs, i, j);
		}
	}
	return p;
}

int CellValue(const Matrix& lhs, const Matrix& rhs, int i, int j)
{
	int sum = 0;
	for (int a = 0; a < rhs.rows_count; a++)
	{
		sum += lhs(i, a) * rhs(a, j);
	}
	return sum;
}