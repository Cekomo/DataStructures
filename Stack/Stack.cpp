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

// Stack::Node Stack::*Peek() {
//     Stack::Node *top = head;
//     return top;
// }

bool Stack::IsEmpty() {

}

int Stack::GetSize() {

}

void Stack::Clear() {

}

Stack::~Stack() {}