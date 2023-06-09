#ifndef DATASTRUCTURES_BINARYTREE_H
#define DATASTRUCTURES_BINARYTREE_H

#include <iostream>

class BinaryTree {
private:
    struct Node {
        Node *leftChild = nullptr;
        Node *rightChild = nullptr;
        int data = 0; // data is a value

        Node(int data);
    };

    Node *root;

public:
    BinaryTree();
    ~BinaryTree();
    void Insert(int data);
    void Remove();
    bool Search(int);
    int GetTreeHeight(Node*);
    int GetNodeLevel();
    int GetTreeSize();
};

#endif //DATASTRUCTURES_BINARYTREE_H
