#ifndef STACK_H
#define STACK_H

class Stack: public LinkedList
{
public:
    Stack();
    ~Stack();
    void push(int);
    int pop();
    int& top();
};

#endif
