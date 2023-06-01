#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>

class LinkedList { // NOTE: Data of nodes made by integer
public:
    LinkedList();
    LinkedList CreateLinkedList();
    bool IsEmpty();
    int GetSize();

    void InsertAtHead(int);
    void InsertAtPosition(int, int);
    void InsertAtTail(int);
    void RemoveFromHead();
    void RemoveFromPosition(int);
    void RemoveFromTail();
    void PrintNodes();

    ~LinkedList();

private:
    struct Node {
        int data;
        Node *next;

        Node(int value);
    };

    Node *head;
    int size;
};

#endif
