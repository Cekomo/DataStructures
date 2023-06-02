#include "Queue.h"

Queue::Queue() {
    rear = nullptr;
    size = 0;
}

void Queue::Enqueue(int value) {
//    Node *newNode = new Node(value);
}

void Queue::Dequeue() {

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