#include "Trie.h"

Trie::Trie() = default;

struct Node {
    std::string letter;
    Node *next[5];

    explicit Node(std::string letter) {
        this->letter = letter;
        for (int i = 0; i < 5; i++)
            next[i] = nullptr;
    }
};

void Trie::Insert(char letter, std::string path, bool isConcluded) {
    Node *node = new Node(letter);

    if (head == nullptr) {
        head = node;
        return;
    }

    Node *currentNode = head;
    char currentLetter = path[0];
    if (currentLetter != head->letter) return;

    for (std::size_t i = 0; i < path.length(); i++) { // p a t h
        currentLetter = path[i];
        for (int j = 0; j < 5 && &currentNode->next[j] == nullptr; j++) {
            if (currentNode->next[j].letter == currentLetter) {
                currentNode = &currentNode->next[j];
                break;
            }
        }
    }

}

Trie::~Trie() = default;