#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector(int size, int* elements) : size(size)
{
    this->elements = nullptr;
    if (size > 0)
    {
        this->elements = new int[this->size];
        if (elements == nullptr)
        {
            for (int i = 0; i < this->size; i++)
            {
                this->elements[i] = 0;
            }
        }
        else for (int i = 0; i < this->size; i++)
        {
            this->elements[i] = elements[i];
        }
    }
    else this->size = 0;
}

Vector::~Vector()
{
    if(this->elements != nullptr) delete[] this->elements;
}

int Vector::operator()(int i) const
{
    return this->elements[i];
}

int& Vector::operator()(int i)
{
    return *(this->elements+i);
}

Vector::Vector(const Vector& v)
{
    this->size = v.size;
    this->elements = new int[this->size];
    for (int i = 0; i < this->size;i++)
    {
        this->elements[i] = v.elements[i];
    }
}

Vector& Vector::operator=(const Vector& v)
{
    if (this->elements != v.elements)
    {
        delete[] this->elements;
        this->size = v.size;
        this->elements = new int[this->size];
        for (int i = 0; i < this->size;i++)
        {
            this->elements[i] = v.elements[i];
        }
    }
    return *this;
}

Vector Vector::operator--(int)
{
    Vector temp(*this);
    if (this->size > 1)
    {
        int* p = this->elements;
        this->elements = new int[--this->size];
        for (int i = 0; i < this->size; i++)
        {
            this->elements[i] = p[i];
        }
        delete[] p;
    }
    else if (this->size-- == 1) delete[] this->elements;
    return temp;
}

Vector& Vector::operator++()
{
    int* p = this->elements;
    this->elements = new int[++this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->elements[i] = p[i];
    }
    this->elements[this->size - 1] = 0;
    delete[] p;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
    os << "[ ";
    for (int i = 0; i < vector.size; i++)
    {
        os << vector.elements[i] << " ";
    }
    os << "]";
    return os;
}
