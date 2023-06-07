#include "HashTable.h"

HashTable::HashTable(int bucketSize) {
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

int HashTable::GetValue(std::string key) {
    int bucketIndex = ComputeHashCode(key);
    Node *currentNode = buckets[bucketIndex].head;
    if (currentNode == nullptr) return 0;

    while (currentNode != nullptr && currentNode->key != key) {
        currentNode = currentNode->next;
    }

    if (currentNode == nullptr) return 0;
    return currentNode->data;
}

void HashTable::Remove(std::string key) {
    int bucketIndex = ComputeHashCode(key);
    Node *currentNode = buckets[bucketIndex].head;
    if (currentNode == nullptr) return;

    Node *previousNode = nullptr;
    while (currentNode != nullptr && currentNode->key != key) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == nullptr) return;
    if (currentNode == buckets[bucketIndex].head) // previousNode == nullptr is valid
        buckets[bucketIndex].head = currentNode->next;
    else
        previousNode->next = currentNode->next;

    delete currentNode;
    nodeSize = nodeSize - 1;
}

bool HashTable::ContainsKey(std::string key) {
    int bucketIndex = ComputeHashCode(key);
    Node *currentNode = buckets[bucketIndex].head;
    if (currentNode == nullptr) return false;

    while (currentNode != nullptr && currentNode->key != key) {
        currentNode = currentNode->next;
    }

    return currentNode->key == key;
}

int HashTable::GetSize() {
    return nodeSize;
}

bool HashTable::IsEmpty() {
    return nodeSize == 0;
}

void HashTable::Clear() {
    for (int bucketIndex = 0; bucketIndex < bucketSize; bucketIndex++) {
        Node *currentNode = buckets[bucketIndex].head;

        while (currentNode != nullptr) {
            Node *previousNode = currentNode;
            currentNode = currentNode->next;
            delete previousNode;
        }

        buckets[bucketIndex].head = nullptr;
    }

    nodeSize = 0;
}


void HashTable::Resize(int newSize) { // method only allows increasing bucket size
    if (newSize < bucketSize) return;

    Bucket *newBuckets = new Bucket[newSize];
    for (int bucketIndex = 0; bucketIndex < bucketSize; bucketIndex++) {
        Node *currentNode = buckets[bucketIndex].head;

        while (currentNode != nullptr) {
            int newBucketIndex = ComputeHashCode(currentNode->key) % newSize;
            Node *newNode = new Node(currentNode->key, currentNode->data);

            // I DID NOT UNDERSTAND HERE AND TAKE FROM GPT-3
            newNode->next = newBuckets[newBucketIndex].head;
            newBuckets[newBucketIndex].head = newNode;
            // ---------------------------------------------

            currentNode = currentNode->next;
        }
    }

    delete[] buckets;
    buckets = newBuckets;
    bucketSize = newSize;
}

HashTable::~HashTable() {
    delete buckets; // delete buckets array
}