#pragma once

#include <ostream>
#include "Vector.h"

class Matrix {

private:
    Vector** rows;
    int rows_count;
    int columns_count;

public:
    Matrix() = delete;

    Matrix(int rows_count, int columns_count);
    ~Matrix();
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    int operator()(int i, int j) const;
    int& operator()(int i, int j);

    Matrix(const Matrix& matrix);
    Matrix& operator=(const Matrix& matrix);

    Matrix& operator--();

    friend Matrix* operator*(const Matrix& lhs, const Matrix& rhs);
    friend int CellValue(const Matrix& lhs, const Matrix& rhs, int i, int j);
};

