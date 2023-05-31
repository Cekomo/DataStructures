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

    newNode->next = this->head;
    this->head = newNode;

    this->size = this->size + 1;
}

void LinkedList::InsertAtTail(int value) {
    Node *newNode = new Node(value);

    if (this->head == nullptr) {
        this->head = newNode;
    }
    else {
        Node *currentNode = this->head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
    }

    this->size = this->size + 1;
    }

void LinkedList::InsertAtPosition(int value, int position) {

    if (position == 0) {
        InsertAtHead(value);
        return;
    }

    Node *newNode = new Node(value);
    Node *currentNode = head;
    int posCounter = 0;

    while (posCounter < position - 1 && currentNode->next != nullptr) {
        currentNode = currentNode->next;
        posCounter++;
    }
    if (currentNode->next != nullptr) {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    else { // if position out of range, assign it at tail's place
        currentNode->next = newNode;
    }

    size = size + 1;
}

void LinkedList::RemoveFromHead() {

}

void LinkedList::RemoveFromPosition(int position) {

}

void LinkedList::RemoveFromTail() {

}

LinkedList::~LinkedList()  {

}