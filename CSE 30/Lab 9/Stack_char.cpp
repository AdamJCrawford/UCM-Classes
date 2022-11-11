#include <iostream>

#include "LinkedList_char.h"
#include "Stack_char.h"

using namespace std;

Stack::Stack()
{
}


Stack::~Stack()
{
}


void Stack::push(char value)
{
    insertAtBack(value);
}


char Stack::pop()
{
    char a = (*last).val;

    removeFromBack();
    return a;
}


char& Stack::top()
{
    return (*last).val;
}
