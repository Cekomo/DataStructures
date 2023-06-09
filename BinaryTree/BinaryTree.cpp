#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::Insert(int data) {

}

void BinaryTree::Remove() {

}

bool BinaryTree::Search(int key) {
    if (root == nullptr) return false;
    Node *currentNode = root;

    while (currentNode != nullptr) {
        if (key < currentNode->data)
            currentNode = currentNode->leftChild;
        else if (key > currentNode->data)
            currentNode = currentNode->rightChild;
        else
            return true;
    }

    return false;
}

int BinaryTree::GetTreeHeight() {
    return 0;
}

int BinaryTree::GetNodeLevel() {
    return 0;
}

int BinaryTree::GetTreeSize() {
    return 0;
}

BinaryTree::~BinaryTree() {

}