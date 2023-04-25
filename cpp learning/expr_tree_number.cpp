#include<iostream>
#include "expr_tree_number.h"

ExprTreeNumber::ExprTreeNumber(int value) : value(value)
{
}

void ExprTreeNumber::addRight(ExprTree* child)
{
	throw std::exception("Thi is a leaf node!");
}

int ExprTreeNumber::calculate() const
{
	return this->value;
}
