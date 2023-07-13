#include "Trie.h"

Trie::Trie() = default;

void Trie::Insert(char letter, std::string path, bool isConcluded) {
    Node *node = new Node(letter);

    if (head == nullptr)
        head = node;
    else {
        char c = path[0];
        if (c != letter) return;

        for (std::size_t i = 0; i < path.length(); i++) {
            c = path[i];

        }
    }
}

Trie::~Trie() = default;