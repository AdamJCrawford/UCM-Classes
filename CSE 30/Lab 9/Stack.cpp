#include <iostream>

#include "LinkedList.h"
#include "Stack.h"

using namespace std;

Stack::Stack()
{
}


Stack::~Stack()
{
}


void Stack::push(int value)
{
    insertAtBack(value);
}


int Stack::pop()
{
    int a = (*last).val;

    removeFromBack();
    return a;
}


int& Stack::top()
{
    return (*last).val;
}
