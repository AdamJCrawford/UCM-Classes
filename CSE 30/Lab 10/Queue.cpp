#include <iostream>

#include "LinkedList.h"
#include "Queue.h"

using namespace std;

Queue::Queue()
{
}


Queue::~Queue()
{
}


void Queue::enqueue(int value)
{
    insertAtBack(value);
}


int Queue::dequeue()
{
    if (isEmpty())
    {
        throw -1;
    }
    else
    {
        int a = (*first).val;

        removeFromFront();
        return a;
    }
}


int& Queue::front()
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
