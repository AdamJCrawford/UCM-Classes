#ifndef STACKCHAR_H
#define STACKCHAR_H

class Stack: public LinkedList
{
public:
    Stack();
    ~Stack();
    void push(char);
    char pop();
    char& top();
};

#endif
