#include "HashTable.h"

HashTable::HashTable(int bucketSize) {
    buckets = new Bucket[bucketSize];
}

// key is assumed as array of chars, names in real life
int HashTable::ComputeHashCode(std::string key) {
    int keyLength = key.length();
    if (keyLength < 2) return 0;

    // capital letter existence is NOT handled
    int firstLetterIndex = (int)key[0] - 96;
    int secondLastLetterIndex = (int)key[keyLength-2] - 96;
    int lastLetterIndex = (int)key[keyLength-1] - 96;

    int keyLetterSum = 0;
    for (int i = 0; i < keyLength; i++)
        keyLetterSum += ((int)key[i] - 96);

    int hashCode = firstLetterIndex * 1000000 + keyLetterSum * 10000 + secondLastLetterIndex * 100 + lastLetterIndex;

    int onesDigitofSum = GetDigit(hashCode, keyLength-5);
    int hashDigitSum = 0;
    for (int i = 0; i < keyLength; i++)
        hashDigitSum += GetDigit(hashCode, i);

    int hashSumLength = 1;
    if (hashDigitSum / 10 >= 1) hashSumLength = 2;
    return (10 * onesDigitofSum) + GetDigit(hashDigitSum, hashSumLength-1);
}

int GetDigit(int number, int position) {
    int divisor = 1;
    for (int i = 1; i < position; i++)
        divisor *= 10;

    return (number / divisor) % 10;
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

/* ISSUES ABOUT THE CODE
 Handling capital letters: The code assumes that all letters in the key are lowercase. If the key contains uppercase
 letters, it may lead to incorrect hash code computation. You may want to consider converting the key to lowercase
 or apply a consistent capitalization rule before computing the hash code.

 Integer overflow: The computation of the hash code involves multiplication and addition of large numbers. Depending
 on the size of the input key, there is a possibility of integer overflow, which can lead to unexpected behavior
 and incorrect hash codes. It's important to ensure that the hash code calculation does not exceed the limits of the
 integer data type.

 Distribution and collisions: The effectiveness of the hash code computation depends on the distribution of hash
 codes and the potential for collisions. The current implementation considers the sum of the ASCII values of the
 key's characters. While this approach can work for certain cases, it may not produce a well-distributed hash code
 or handle collisions efficiently, especially for keys with similar letter distributions.

 Bucket index calculation: The code extracts specific digits from the hash code and uses them to calculate the bucket
 index. This approach may not provide a uniform distribution of key-value pairs across the hash table, especially if
 the extracted digits do not adequately represent the overall hash code.
 */