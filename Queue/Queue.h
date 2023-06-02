#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

#include <iostream>

class Queue {
private:
    struct Node {
        int data;
        Node *next;

        Node(int data);
    };

    Node *rear;
    Node *front; // may not be used in anywhere
    int size;

public:
    Queue();
    ~Queue();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
    bool IsEmpty();
    int GetSize();
    void Clear();
};


#endif //DATASTRUCTURES_QUEUE_H
