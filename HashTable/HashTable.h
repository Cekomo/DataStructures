#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H

#include <iostream>

class HashTable {
private:
    struct Node {
        int key; // I am not sure if this is correct
        int data;
        Node *next;

        Node(int key, int data);
    };

    struct Bucket {
        int hashCode = 0;
        Node *head = nullptr;

        // Bucket(); // necessary if custom constructor is needed
    };

    int bucketSize;
    int nodeSize;
    Bucket *buckets;

public:
    HashTable();
    ~HashTable();

    void Insert(int key, int data);
    int GetValue(int key);
    void Remove(int key);
    bool ContainsKey(int key);

    int GetSize();
    bool IsEmpty();
    void Clear();
    void Resize(int newSize);
};

#endif //DATASTRUCTURES_HASHTABLE_H