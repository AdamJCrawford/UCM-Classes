#include <iostream>

#include "LinkedList.h"
#include "Stack.h"

using namespace std;


int main()
{
    Stack stack;

    stack.isEmpty() ? cout << "Stack is empty" << endl : cout << "Stack is not empty" << endl;
    stack.push(10);
    stack.push(11);
    stack.push(12);
    stack.push(13);
    stack.push(14);
    cout << stack.top() << endl;
    stack.push(15);
    stack.push(16);
    stack.push(17);
    stack.push(18);
    cout << stack.pop() << endl;
    stack.push(19);
    stack.push(20);
    stack.print();
    cout << endl << stack.top();
    cout << endl << stack.pop() << endl;
    stack.print();
    cout << endl << stack.top() << endl;
    stack.isEmpty() ? cout << "Stack is empty" << endl : cout << "Stack is not empty" << endl;
    return 0;
}
