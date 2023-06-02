#include "Stack.h"

Stack::Stack() {
    top = nullptr;
    size = 0;
}

void Stack::Push(int value) {
    Node *topNode = new Node(value);
    topNode->next = top;
    top = topNode;

    size = size + 1;
}

void Stack::Pop() {
    if (top == nullptr) return;

    Node *topNode = top;
    top = topNode->next;
    delete topNode;

    size = size - 1;
}

int Stack::Peek() { // it's correct as long as data type is integer
    if (top == nullptr) return -1;

    Node *topNode = top;
    return topNode->data;
}

bool Stack::IsEmpty() {
    //    return size == 0;
    return top == nullptr;
}

int Stack::GetSize() {
    return size;
}

void Stack::Clear() {
    Node *currentNode = top;
    while (currentNode != nullptr) {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    top = nullptr;
    size = 0;
}

Stack::~Stack() {}