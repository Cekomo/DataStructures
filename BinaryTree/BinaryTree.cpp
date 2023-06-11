#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::Insert(int key) {
    Node *newNode = new Node(key);
    Node *currentNode = root;
    if (currentNode == nullptr) {
        root = newNode;
        return;
    }

    Node *previousNode = nullptr;
    while (currentNode != nullptr) {
        previousNode = currentNode;
        if (data < currentNode->data) {
            currentNode = currentNode->leftChild;
        }
        else if (key > currentNode->data) {
            currentNode = currentNode->rightChild;
        }
        else {
            delete newNode;
            return;
        }
    }

    if (key < previousNode->data) {
        previousNode->leftChild = newNode;
    }
    else if (key > previousNode->data) {
        previousNode->rightChild = newNode;
    }
}

void BinaryTree::Remove(int key) {
    Node *currentNode = root;
    if (currentNode == nullptr) return;

    Node *previousNode = nullptr;
    while (currentNode != nullptr) {
        if (key < currentNode->data) {
            previousNode = currentNode;
            currentNode = currentNode->leftChild;
        }
        else if (key > currentNode->data) {
            previousNode = currentNode;
            currentNode = currentNode->rightChild;
        }
        else
            break;
    }
    if (currentNode == nullptr) return;

    // handle the leaf removal
    if (currentNode->leftChild == nullptr && currentNode->rightChild == nullptr) {
        if (previousNode == nullptr)
            root = nullptr;
        else if (previousNode->leftChild == currentNode)
            previousNode->leftChild = nullptr;
        else if (previousNode->rightChild == currentNode)
            previousNode->rightChild = nullptr;

        delete currentNode;
    }

    // handle the parent removal
    

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

int BinaryTree::GetTreeHeight(Node *currentNode) {
    if (currentNode == nullptr) return 0;

    int leftHeight = BinaryTree::GetTreeHeight(currentNode->leftChild);
    int rightHeight = BinaryTree::GetTreeHeight(currentNode->rightChild);

    if (leftHeight > rightHeight) return leftHeight + 1;
    return rightHeight + 1;
}

int BinaryTree::GetNodeDepth(Node *node) {
    Node *currentNode = root;
    if (root == nullptr) return -1;
    int nodeDepth = 0;

    while (currentNode != nullptr) {
        if (node->data < currentNode->data) {
            currentNode = currentNode->leftChild;
            nodeDepth++;
        }
        else if (node->data > currentNode->data) {
            currentNode = currentNode->rightChild;
            nodeDepth++;
        }
        else
            return nodeDepth;
    }

    return -1;
}

int BinaryTree::GetTreeSize(Node *currentNode) {
    if (currentNode == nullptr) return 0;

    int treeSizeLeft = GetTreeSize(currentNode->rightChild);
    int treeSizeRight = GetTreeSize(currentNode->leftChild);

    return treeSizeLeft + treeSizeRight + 1;
}

BinaryTree::~BinaryTree() {

}