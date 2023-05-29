#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

// NOTE: Data of nodes made by integer

class LinkedList {
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

private:
    struct Node;
    int size;
};

#endif
