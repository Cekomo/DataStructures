#include "LinkedList.h"
#include <iostream>

struct Node {
    int data; // considering the data is a number
    struct Node *next;
};

LinkedList::LinkedList()  {
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
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

}

void LinkedList::InsertAtPosition(int value, int position) {

}

void LinkedList::InsertAtTail(int value) {

}

void LinkedList::RemoveFromHead() {

}

void LinkedList::RemoveFromPosition(int position) {

}

void LinkedList::RemoveFromTail() {
    
}

//struct LinkedListStruct {
//
//
//    int size;
//
//    LinkedListStruct() {
//        head = nullptr;
//        tail = nullptr;
//    }
//
//    LinkedListStruct CreateLinkedList() {
//        LinkedListStruct list = LinkedListStruct();
//        list.size = 0;
//        return list;
//    }
//
//    bool IsEmpty() {
//        return this->size == 0;
//    }
//
//    int GetSize() {
//        return this->size;
//    }
//};

