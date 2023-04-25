#include <iostream>
#include "parser.h"
#include "expr_tree.h"
#include "expr_tree_number.h"
#include "expr_tree_negation.h"
#include "expr_tree_subtraction.h"

void Lab9()
{

    ExprTreeNumber number(5);
    std::cout << "Expected result: 5" << std::endl;
    std::cout << "Result: " << number.calculate() << std::endl;
    
    ExprTree *x = new ExprTreeNumber(3);
    std::cout << "Expected result: 3" << std::endl;
    std::cout << "Result: " << x->calculate() << std::endl;
    delete x;
    
 
    ExprTree *num = new ExprTreeNumber(6);
    ExprTree *neg = new ExprTreeNegation(num);
    std::cout << "Expected result: -6" << std::endl;
    std::cout << "Result: " << neg->calculate() << std::endl;

    delete neg;
    
    ExprTree *num1 = new ExprTreeNumber(6);
    ExprTree *num2 = new ExprTreeNumber(4);
    ExprTree *sub = new ExprTreeSubtraction(num1, num2);
    std::cout << "Expected result: 2" << std::endl;
    std::cout << "Result: " << sub->calculate() << std::endl;

    delete sub;
    

    
    std::string expression;
    std::cout << "This is a calculator of negative arithmetic expressions."
              << std::endl << "It accepts only numbers and - operator."
              << std::endl << "For example such expression: "
              << "'   -- ---23- 3  ---- -3-3  ' should evaluate to -32."
              << std::endl;
    std::cout << "Input expression to compute:" << std::endl;
    std::string xd;
    std::getline(std::cin, xd);
    std::getline(std::cin, expression);
    Parser parser;
    if(!parser.parse(expression)) {
        std::cout << "The expression is incorrect." << std::endl;
        return;
    }
    ExprTree *tree = parser.getExpression();
    std::cout << "Result: " << tree->calculate() << std::endl;
    delete tree;
    
}