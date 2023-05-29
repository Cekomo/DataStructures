#include "LinkedList.h"
#include <iostream>

struct Node {
    int data; // considering the data is a number
    struct Node *next;
};

struct LinkedList {

    Node *head;
    Node *tail;
    int size;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    LinkedList CreateLinkedList() {
        LinkedList list = LinkedList();
        list.size = 0;
        return list;
    }

    bool IsEmpty() {
        return this->size == 0;
    }

    int GetSize() {
        return this->size;
    }
};

