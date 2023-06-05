#include "HashTable.h"

HashTable::HashTable() {
    bucketSize = 10;
    buckets = new Bucket[bucketSize];
}

int HashTable::ComputeHashCode(std::string key) {
    return 0;
}

// do not forget that if you LINK, you MUST handle NEXT pointer
void HashTable::Insert(std::string key, int data) {
    Node *newNode = new Node(key, data);

    int bucketIndex = ComputeHashCode(newNode->key);
    if (buckets[bucketIndex].head == nullptr) {
        buckets[bucketIndex].head = newNode;
    }
    else {
        Node *currentNode = buckets[bucketIndex].head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
    }
}

int HashTable::GetValue(int key) {
    return 0;
}

void HashTable::Remove(int key) {

}

bool HashTable::ContainsKey(int key) {
    return false;
}

int HashTable::GetSize() {
    return nodeSize;
}

bool HashTable::IsEmpty() {
    return nodeSize == 0;
}

void HashTable::Clear() {

}

void HashTable::Resize(int newSize) {

}

HashTable::~HashTable() {
    delete buckets; // delete buckets array
}