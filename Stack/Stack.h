#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include <iostream>

class Stack {
private:
    struct Node {
        Node *next;
        int data;

        Node(int data);
    };

    Node *top;
    int size;

public:
    Stack();
    ~Stack();
    void Push(int value);
    void Pop();
    int Peek();
    bool IsEmpty();
    int GetSize();
    void Clear();
};

#endif
