#ifndef QUEUE_H
#define QUEUE_H

class Queue : public LinkedList
{
public:
    Queue();
    ~Queue();
    void enqueue(int);
    int dequeue();
    int& front();
};

#endif
