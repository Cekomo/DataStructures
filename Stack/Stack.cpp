#include "Stack.h"

Stack::Stack() {
    head = nullptr;
    size = 0;
}

void Stack::Push(int value) {
    Node *topNode = new Node(value);
    topNode->next = head;
    head = topNode;

    size = size + 1;
}

void Stack::Pop() {
    if (head == nullptr) return;

    Node *topNode = head;
    head = topNode->next;
    delete topNode;

    size = size - 1;
}

int Stack::Peek() { // it's correct as long as data type is integer
    if (head == nullptr) return -1;

    Node *topNode = head;
    return topNode->data;
}

bool Stack::IsEmpty() {
    //    return size == 0;
    return head == nullptr;
}

int Stack::GetSize() {
    return size;
}

void Stack::Clear() {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    head = nullptr;
    size = 0;
}

Stack::~Stack() {}