#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include <iostream>

class Stack {
private:
    struct Node {
        Node *next;
        int value;

        Node(int value);
    };

    Node *head;
    int size;

public:
    Stack();
    ~Stack();
    void Push();
    void Pop();
    Node *Peek();
    bool IsEmpty();
    int GetSize();
    void Clear();
};

#endif
