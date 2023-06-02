#include <iostream>
#include <complex>
#include <string>
#include <vector>
#include <algorithm>
#include "myStack.h"
using namespace std;

// Stage 2 & 3
template<int T>
int convert_to_decimal_system(string s)
{
	/*myStack<char> abc;
	abc.initializeStack();
	abc.top(s[i]);
	try {
		if (T >=2 && T<=9) {
			int sum = 0;
			if (s.length() > 0)
			{
				for (int i = s.length() - 1; i >= 0; i--)
				{
					sum += pow(T, i) * (s[i] - 48);
				}
			}
			return sum;
		}
		else {
			throw (out_of_range("Wrong nuber"));
		}
	}
	catch (out_of_range) {
		return 0;
	}*/return 0;
}

void Lab13()
{
	//std::cout << std::endl << " --------------------- STAGE_0 (0 Pts) --------------------- " << std::endl;
	//// Comment STAGE_0 before staring

	//myStack stack;
	//myStack otherStack;
	//myStack newStack;

	//cout << "Stack content, stack: "
	//	<< endl;
	//cout << stack << endl;

	////Add elements into stack
	//stack.push(34);
	//stack.push(43);
	//stack.push(27);

	//cout << "Stack content, stack: "
	//	<< endl;
	//cout << stack << endl;

	////Use the assignment operator to copy the elements
	////of stack into newStack
	//newStack = stack;

	//cout << "After the assignment operator, newStack: "
	//	<< endl;

	////Output the elements of newStack
	//while (!newStack.isEmptyStack())
	//{
	//	cout << newStack.top() << endl;
	//	newStack.pop();
	//}
	//cout << endl;

	////Use the assignment operator to copy the elements
	////of stack into otherStack
	//otherStack = stack;

	//cout << "Testing the copy constructor." << endl;

	//myStack testCopy(otherStack);

	//cout << "After the copy constructor, testCopy: " << endl;

	//while (!testCopy.isEmptyStack())
	//{
	//	cout << testCopy.top() << endl;
	//	testCopy.pop();
	//}


	/*std::cout << std::endl << " --------------------- STAGE_1 (5 Pts) --------------------- " << std::endl;
	
	myStack<int> stack;
	myStack<int> otherStack;
	myStack<int> newStack;

	cout << "Stack content, stack: "
		<< endl;
	cout << stack << endl;

	//Add elements into stack
	stack.push(34);
	stack.push(43);
	stack.push(27);

	cout << "Stack content, stack: "
		<< endl;
	cout << stack <<endl;

	//Use the assignment operator to copy the elements
	//of stack into newStack
	newStack = stack;

	cout << "After the assignment operator, newStack: "
		<< endl;

	//Output the elements of newStack
	while (!newStack.isEmptyStack())
	{
		cout << newStack.top() << endl;
		newStack.pop();
	}
	cout << endl;

	//Use the assignment operator to copy the elements
	//of stack into otherStack
	otherStack = stack;

	cout << "Testing the copy constructor." << endl;

	myStack<int> testCopy(otherStack);

	cout << "After the copy constructor, testCopy: " << endl;

	while (!testCopy.isEmptyStack())
	{
		cout << testCopy.top() << endl;
		testCopy.pop();
	}
	cout << endl;

	myStack<string> sstack;
	myStack<string> sotherStack;
	myStack<string> snewStack;

	cout << "Stack content, stack: "
		<< endl;
	cout << sstack << endl;

	//Add elements into stack
	sstack.push("programming");
	sstack.push("love");
	sstack.push("I");

	cout << "Stack content, stack: "
		<< endl;
	cout << sstack << endl;

	//Use the assignment operator to copy the elements
	//of stack into newStack
	snewStack = sstack;

	cout << "After the assignment operator, newStack: "
		<< endl;

	//Output the elements of newStack
	while (!snewStack.isEmptyStack())
	{
		cout << snewStack.top() << endl;
		snewStack.pop();
	}
	cout << endl;

	//Use the assignment operator to copy the elements
	//of stack into otherStack
	sotherStack = sstack;

	cout << "Testing the copy constructor." << endl;

	myStack<string> stestCopy(sotherStack);

	cout << "After the copy constructor, testCopy: " << endl;

	while (!stestCopy.isEmptyStack())
	{
		cout << stestCopy.top() << endl;
		stestCopy.pop();
	}
	
	std::cout << std::endl << " --------------------- STAGE_2 (2 Pts) --------------------- " << std::endl;
	
	cout << convert_to_decimal_system<2>("1111") << endl;
	cout << convert_to_decimal_system<8>("17") << endl;
	
	std::cout << std::endl << " --------------------- STAGE_3 (1 Pts) --------------------- " << std::endl;
	
	cout << convert_to_decimal_system<16>("1111") << endl;*/
	
}


