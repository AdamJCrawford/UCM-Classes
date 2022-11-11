#include <iostream>

#include "LinkedList_char.h"
#include "Stack_char.h"

using namespace std;


int main()
{
    Stack stack;

    cout << "isEmpty()" << "\t";
    stack.isEmpty()? cout << "true" : cout << "false";
    cout << "\t";
    stack.print();

    cout << endl << "top()" << "\t";
    cout << stack.top();
    cout << "\t";
    stack.print();

    cout << endl << "push(A)" << "\t\t";
    stack.push('A');
    cout << "\t";
    stack.print();

    cout << endl << "push(Y)" << "\t\t";
    stack.push('Y');
    cout << "\t";
    stack.print();

    cout << endl << "size()" << "\t\t" << stack.size() << "\t";
    stack.print();

    cout << endl << "pop()" << "\t\t" << stack.pop() << "\t";
    stack.print();

    cout << endl << "isEmpty()" << "\t";
    stack.isEmpty()? cout << "true" : cout << "false";
    cout << "\t";
    stack.print();

    cout << endl << "push(D)" << "\t\t";
    stack.push('D');
    cout << "\t";
    stack.print();

    cout << endl << "top()" << "\t\t" << stack.top() << "\t";
    stack.print();

    cout << endl << "push(T)" << "\t\t";
    stack.push('T');
    cout << "\t";
    stack.print();

    cout << endl << "pop()" << "\t\t" << stack.pop() << "\t";
    stack.print();

    return 0;
}
