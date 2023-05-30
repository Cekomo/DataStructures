#include "LinkedList.h"
#include <iostream>

struct Node {
    int data; // considering the data is a number
    struct Node *next;

    explicit Node(int value) {
        data = value;
        next = nullptr;
    }
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList LinkedList::CreateLinkedList() {
    LinkedList link = LinkedList();
    return link;
}

bool LinkedList::IsEmpty() {
    return this->size == 0;
}

int LinkedList::GetSize() {
    return this->size;
}

void LinkedList::InsertAtHead(int value) {
    Node *newNode = new Node(value);

    if (this->head == nullptr) {
        this->head = newNode;
    }
    else {
        newNode->next = this->head;
        this->head = newNode;
    }
}

void LinkedList::InsertAtTail(int value) {
    Node *newNode = new Node(value);

    if (this->head == nullptr) {
        this->head = newNode;
    }
    else {
        Node *currentNode = this->head;
        for (int i = 0; i < this->size; i++) {
            if (currentNode->next == nullptr) {
                // we found the last node placement
            }
        }
    }
}

void LinkedList::InsertAtPosition(int value, int position) {


}

void LinkedList::RemoveFromHead() {

}

void LinkedList::RemoveFromPosition(int position) {

}

void LinkedList::RemoveFromTail() {

}

LinkedList::~LinkedList()  {

}