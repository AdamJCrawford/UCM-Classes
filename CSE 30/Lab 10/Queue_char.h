#ifndef QUEUECHAR_H
#define QUEUECHAR_H

class Queue: public LinkedList
{
public:
    Queue();
    ~Queue();
    void enqueue(char);
    char dequeue();
    char &front();

};

#endif
