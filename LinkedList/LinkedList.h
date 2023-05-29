#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

class LinkedList {
public:
    LinkedList();
    LinkedList CreateLinkedList();
    bool IsEmpty();
    int GetSize();

private:
    struct Node;

};

#endif //LINKEDLIST_LINKEDLIST_H
