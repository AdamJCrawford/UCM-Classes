#include <iostream>

#include "LinkedList_char.h"
#include "Queue_char.h"

using namespace std;

Queue::Queue()
{
}


Queue::~Queue()
{
}


void Queue::enqueue(char value)
{
    insertAtBack(value);
}


char Queue::dequeue()
{
    if (isEmpty())
    {
        throw -1;
    }
    else
    {
        char a = (*first).val;

        removeFromFront();
        return a;
    }
}


char& Queue::front()
{
    if (isEmpty())
    {
        throw -1;
    }
    else
    {
        return (*first).val;
    }
}
