#pragma once

#include <ostream>

class Vector {

private:
    int* elements;
    int size;

public:
    Vector() = delete;

    Vector(int size, int* elements = nullptr);
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
    ~Vector();
    int operator()(int i) const;
    int& operator()(int i);

    Vector(const Vector& v);
    Vector& operator=(const Vector& v);

    Vector& operator++();
    Vector operator--(int);
};

