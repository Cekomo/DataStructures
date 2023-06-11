#ifndef DATASTRUCTURES_BINARYTREE_H
#define DATASTRUCTURES_BINARYTREE_H

#include <iostream>

class BinaryTree {
private:
    struct Node {
        Node *leftChild = nullptr;
        Node *rightChild = nullptr;
        int data; // data is a value

        Node(int data);
    };

    Node *root;

public:
    BinaryTree();
    ~BinaryTree();
    void Insert(int);
    void Remove(int);
    bool Search(int);
    int GetTreeHeight(Node*);
    int GetNodeDepth(Node*);
    int GetTreeSize(Node*);
};

#endif //DATASTRUCTURES_BINARYTREE_H
