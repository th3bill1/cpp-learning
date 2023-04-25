#include "expr_tree_subtraction.h"

ExprTreeSubtraction::ExprTreeSubtraction(ExprTree* left, ExprTree* right) : left(left), right(right)
{
}

ExprTreeSubtraction::~ExprTreeSubtraction()
{
	delete this->left;
	delete this->right;
}

void ExprTreeSubtraction::addRight(ExprTree* right)
{
	this->right = right;
}

int ExprTreeSubtraction::calculate() const
{
	return this->left->calculate()-this->right->calculate();
}
