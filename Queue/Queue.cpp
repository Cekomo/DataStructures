#include "Queue.h"

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

void Queue::Enqueue(int value) {
    Node *newNode = new Node(value);
    newNode->next = nullptr;

    if (IsEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    size = size + 1;
}

void Queue::Dequeue() {
    if (IsEmpty()) return;

    Node *frontNode = front;
    front = frontNode->next;
    delete frontNode;

    size = size - 1;
}

int Queue::Peek() {
    if (IsEmpty())
        return -1;

    Node *frontNode= front;
    return frontNode->data;
}

bool Queue::IsEmpty() {
    return rear == nullptr;
}

int Queue::GetSize() {
    return size;
}

void Queue::Clear() {

}

Queue::~Queue() {

}