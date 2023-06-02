#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>

#include "stackADT.h"

using namespace std;

template <typename u >
class myStack : public stackADT<u>
{
public:
    const myStack<u>& operator=(const myStack&);
    //Overload the assignment operator.

    void initializeStack();
    //Function to initialize the stack to an empty state.
    //Postcondition: stackTop = 0

    bool isEmptyStack() const;
    //Function to determine whether the stack is empty.
    //Postcondition: Returns true if the stack is empty,
    //               otherwise returns false.

    bool isFullStack() const;
    //Function to determine whether the stack is full.
    //Postcondition: Returns true if the stack is full,
    //               otherwise returns false.

    void push(const u& newItem);
    //Function to add newItem to the stack.
    //Precondition: The stack exists and is not full.
    //Postcondition: The stack is changed and newItem 
    //               is added to the top of the stack.

    u top() const;
    //Function to return the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: If the stack is empty, the program 
    //               terminates; otherwise, the top element
    //               of the stack is returned.

    void pop();
    //Function to remove the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: The stack is changed and the top 
    //               element is removed from the stack.

    myStack(int stackSize = 100);
    //constructor
    //Create an array of the size stackSize to hold 
    //the stack elements. The default stack size is 100.
    //Postcondition: The variable list contains the base
    //               address of the array, stackTop = 0, and  
    //               maxStackSize = stackSize.

    myStack(const myStack<u>& otherStack);
    //copy constructor

    ~myStack();
    //destructor
    //Remove all the elements from the stack.
    //Postcondition: The array (list) holding the stack 
    //               elements is deleted.
    template <typename S>
    friend ostream& operator<<(ostream& out, const myStack<S>& ms);

private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    u* list;       //pointer to the array that holds the
    //stack elements

    void copyStack(const myStack& otherStack);
    //Function to make a copy of otherStack.
    //Postcondition: A copy of otherStack is created and
    //               assigned to this stack.
};

template <typename u>
void myStack<u>::initializeStack()
{
    stackTop = 0;
}//end initializeStack

template <typename u>
bool myStack<u>::isEmptyStack() const
{
    return(stackTop == 0);
}//end isEmptyStack

template <typename u>
bool myStack<u>::isFullStack() const
{
    return(stackTop == maxStackSize);
} //end isFullStack

template <typename u>
void myStack<u>::push(const u& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   //add newItem to the
        //top of the stack
        stackTop++; //increment stackTop
    }
    else
        cout << "Cannot add to a full stack." << endl;
}//end push

template <typename u>
u myStack<u>::top() const
{
    assert(stackTop != 0);          //if stack is empty,
    //terminate the program
    return list[stackTop - 1];      //return the element of the
    //stack indicated by
    //stackTop - 1
}//end top

template <typename u>
void myStack<u>::pop()
{
    if (!isEmptyStack())
        stackTop--;                 //decrement stackTop
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <typename u>
myStack<u>::myStack(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "
            << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //set the stack size to
    //the value specified by
    //the parameter stackSize

    stackTop = 0;                   //set stackTop to 0
    list = new u[maxStackSize];  //create the array to
    //hold the stack elements
}//end constructor

template <typename u>
myStack<u>::~myStack() //destructor
{
    delete[] list; //deallocate the memory occupied
    //by the array
}//end destructor

template <typename u>
void myStack<u>::copyStack(const myStack& otherStack)
{
    delete[] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new u[maxStackSize];

    //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)
        list[j] = otherStack.list[j];
} //end copyStack

template <typename u>
myStack<u>::myStack(const myStack<u>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}//end copy constructor

template <typename u>
const myStack<u>& myStack<u>::operator=(const myStack<u>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
} //end operator=

template <typename u>
ostream& operator<<(ostream& out, const myStack<u>& ms)
{
    if (ms.isEmptyStack())
        out << "Stack is empty" << endl;
    else {
        for (int j = ms.stackTop - 1; j >= 0; j--)
            cout << ms.list[j] << endl;
    }
    return out;
}



#endif