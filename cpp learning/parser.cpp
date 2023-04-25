#include<iostream>
#include "parser.h"
#include "expr_tree.h"
#include "expr_tree_number.h"
#include "expr_tree_negation.h"
#include "expr_tree_subtraction.h"

Parser::Parser()
    : top(nullptr), bottom(nullptr)
{
}

bool Parser::parse(const std::string& input)
{
    for (int i = 0; i < input.size(); i++)
    {
        char c = input[i];
        if (isdigit(c))
        {
            int n = (int)c;
            if (n < 0)
            {
                this->addMinusToTree();
                this->addNumberToTree(n);
            }
        }
        else if ((int)c == 45)
        {
            this->addMinusToTree();
        }
        else return false;
    }
    std::cout << "xD";
    return true;
}

ExprTree* Parser::getExpression() const
{
    return top;
}

bool Parser::addNumberToTree(int num)
{
    ExprTree *expr = new ExprTreeNumber(num);
    if(bottom == nullptr && top == nullptr) {
        top = expr;
    } else if(bottom == nullptr) {
        delete expr;
        return false;
    } else {
        bottom->addRight(expr);
        bottom = nullptr;
    }
    return true;
}

void Parser::addMinusToTree()
{
    if(bottom == nullptr && top == nullptr) {
        ExprTree *expr = new ExprTreeNegation();
        bottom = expr;
        top = bottom;
    } else if(bottom == nullptr) {
        ExprTree *expr = new ExprTreeSubtraction(top);
        top = expr;
        bottom = expr;
    } else {
        ExprTree *expr = new ExprTreeNegation();
        bottom->addRight(expr);
        bottom = expr;
    }
}

void Parser::resetTree()
{
    delete top;
    top = nullptr;
    bottom = nullptr;
}
