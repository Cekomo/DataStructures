#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H

#include <iostream>
#include <string>

class HashTable {
private:
    struct Node {
        std::string key; // I am not sure if this is correct
        int data;
        Node *next;

        Node(std::string key, int data);
    };

    struct Bucket {
        int hashCode = 0;
        Node *head = nullptr;

        // Bucket(); // necessary if custom constructor is needed
    };

    int bucketSize;
    int nodeSize;
    Bucket *buckets;

    int ComputeHashCode(std::string key);

public:
    HashTable();
    ~HashTable();

    void Insert(std::string key, int data);
    int GetValue(std::string key);
    void Remove(std::string key);
    bool ContainsKey(std::string key);

    int GetSize();
    bool IsEmpty();
    void Clear();
    void Resize(int newSize);
};

#endif //DATASTRUCTURES_HASHTABLE_H