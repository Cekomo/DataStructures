#include "HashTable.h"

HashTable::HashTable() {
    bucketSize = 10;
    buckets = new Bucket[bucketSize];
}

void HashTable::Insert(int key, int data) {

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