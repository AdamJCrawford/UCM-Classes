#include <iostream>

#include "LinkedList_char.h"
#include "Queue_char.h"

using namespace std;


int main()
{
    Queue queue;

    cout << "dequeue() \t";
    try
    {
        cout << queue.dequeue() << "\t\t";
        queue.print();
    }
    catch (int e)
    {
        cout << "exception";
    }

    cout << endl << "enqueue(D) \t";
    queue.enqueue('D');
    cout << "\t\t";
    queue.print();

    cout << endl << "enqueue(A) \t";
    queue.enqueue('A');
    cout << "\t\t";
    queue.print();

    cout << endl << "dequeue() \t";
    try
    {
        cout << queue.dequeue() << "\t\t";
        queue.print();
    }
    catch (int e)
    {
        cout << "exception";
    }

    cout << endl << "size() \t\t" << queue.size() << "\t\t";
    queue.print();

    cout << endl << "enqueue(D) \t";
    queue.enqueue('D');
    cout << "\t\t";
    queue.print();

    cout << endl << "isEmpty() \t";
    queue.isEmpty()? cout << "true": cout << "false";
    cout << "\t\t";
    queue.print();

    cout << endl << "front() \t";
    try
    {
        cout << queue.front();
    }

    catch (int e)
    {
        cout << "exception";
    }

    cout << "\t\t";
    queue.print();

    cout << endl << "enqueue(T) \t";
    queue.enqueue('T');
    cout << "\t\t";
    queue.print();

    cout << endl << "front() \t";
    try
    {
        cout << queue.front();
    }

    catch (int e)
    {
        cout << "exception";
    }

    cout << "\t\t";
    queue.print();

    return 0;
}
