#ifndef DATASTRUCTURES_TRIE_H
#define DATASTRUCTURES_TRIE_H

#include <iostream>

class Trie {
private:
    struct Node {
        char letter;
        Node *next;

        Node(char letter);
    };

    int size;
    Node *head;

public:
    Trie();
    void Insert(char letter, std::string path, bool isConcluded);
    ~Trie();
};


#endif //DATASTRUCTURES_TRIE_H
