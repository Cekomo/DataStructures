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
    if (head == nullptr) return;
    size = size - 1;

    Node *firstNode = head;
    head = firstNode->next;

    delete firstNode;
}

void LinkedList::RemoveFromTail() {
    if (head == nullptr) return;
    size = size - 1;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *currentNode = head;
    Node *previousNode = nullptr; // assigned as null to not have indeterminate value
    while (currentNode->next != nullptr) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    previousNode->next = nullptr; // disconnect the link before deleting
    delete currentNode;
}

void LinkedList::RemoveFromPosition(int position) {
    if (head == nullptr || position < 0) return;
    size = size - 1;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    else if (position == 0) {
        Node *firstNode = head;
        delete head;
        head = firstNode->next;
        return;
    }

    Node *currentNode = head;
    Node *previousNode = nullptr;
    int posCounter = 0;
    while (posCounter < position && currentNode->next != nullptr) {
        previousNode = currentNode;
        currentNode = currentNode->next;
        posCounter++;
    }

    // head may not be handled when position=0 and multiple nodes present
    previousNode->next = currentNode->next;
    delete currentNode;
}

LinkedList::~LinkedList()  {

}