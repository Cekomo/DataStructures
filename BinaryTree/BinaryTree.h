#ifndef DATASTRUCTURES_BINARYTREE_H
#define DATASTRUCTURES_BINARYTREE_H

#include <iostream>

class BinaryTree {
private:
    struct Node {
        Node *leftChild;
        Node *rightChild;
        int data; // data is a value

        Node(int data) : leftChild(nullptr), rightChild(nullptr), data(data) {}
    };

    Node *root;

public:
    BinaryTree();
    ~BinaryTree();
    void Insert(int);
    void Remove(int);
    bool Search(int);
    void FixBalance();
    int GetShortestNode(Node*);
    int GetTreeHeight(Node*);
    int GetNodeDepth(Node*);
    int GetTreeSize(Node*);
};

#endif //DATASTRUCTURES_BINARYTREE_H
