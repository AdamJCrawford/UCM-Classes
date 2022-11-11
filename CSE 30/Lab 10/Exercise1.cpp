#include <iostream>

#include "LinkedList.h"
#include "Queue.h"

using namespace std;

int main()
{
    Queue a;

    // There has to be a better way of try/catch tham manually doing every time you want to call a function
    try
    {
        a.front();
    }
    catch (int e)
    {
        cout << "Call to front() generated an exception, because the queue is empty" << endl;
    }

    a.enqueue(9);
    a.enqueue(8);
    a.enqueue(7);
    a.enqueue(6);
    a.enqueue(5);
    a.enqueue(4);
    a.enqueue(3);
    a.enqueue(2);
    a.enqueue(1);

    try

    {
        cout << "front " << a.front() << endl;
    }

    catch (int e)
    {
        cout << "Call to front() generated an exception, because the queue is empty" << endl;
    }

    try

    {
        cout << "remove " << a.dequeue() << endl;
    }

    catch (int e)
    {
        cout << "Call to dequeue() generated an exception, because the queue is empty" << endl;
    }

    try

    {
        cout << "front " << a.front() << endl;
    }

    catch (int e)
    {
        cout << "Call to front() generated an exception, because the queue is empty" << endl;
    }

    cout << "size " << a.size() << endl;

    a.isEmpty() ? cout << "Stack is empty" << endl : cout << "Stack is not empty" << endl;

    try
    {
        a.dequeue();
        a.dequeue();
        a.dequeue();
        a.dequeue();
        a.dequeue();
        a.dequeue();
        a.dequeue();
        a.dequeue();
        a.dequeue();
    }


    catch (int e)
    {
        cout << "Call to dequeue() generated an exception, because the queue is empty" << endl;
    }

    try
    {
        cout << a.front() << endl;
    }
    catch (int e)
    {
        cout << "Call to front() generated an exception, because the queue is empty" << endl;
    }

    a.enqueue(9);
    try
    {
        cout << "front " << a.front() << endl;
    }
    catch (int e)
    {
        cout << "Call to front() generated an exception, because the queue is empty" << endl;
    }


    return 0;
}
