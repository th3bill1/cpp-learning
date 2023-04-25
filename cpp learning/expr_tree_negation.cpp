#include "expr_tree_negation.h"

ExprTreeNegation::ExprTreeNegation(ExprTree* child) : child(child)
{
}

ExprTreeNegation::~ExprTreeNegation()
{
	delete this->child;
}

void ExprTreeNegation::addRight(ExprTree* right)
{
	this->child = right;
}

int ExprTreeNegation::calculate() const
{
	return -this->child->calculate();
}
