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
        if (key < currentNode->data) {
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
    Node *previousNode = nullptr;

    while (currentNode != nullptr && currentNode->data != key) {
        previousNode = currentNode;
        if (key < currentNode->data)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }

    if (currentNode == nullptr) return;

    if (currentNode->leftChild == nullptr && currentNode->rightChild == nullptr) {
        if (previousNode == nullptr)
            root = nullptr;
        else if (previousNode->leftChild == currentNode)
            previousNode->leftChild = nullptr;
        else
            previousNode->rightChild = nullptr;

        delete currentNode;
    }
    else if (currentNode->leftChild == nullptr || currentNode->rightChild == nullptr) {
        Node* childNode = (currentNode->leftChild != nullptr) ? currentNode->leftChild : currentNode->rightChild;

        if (previousNode == nullptr)
            root = childNode;
        else if (previousNode->leftChild == currentNode)
            previousNode->leftChild = childNode;
        else
            previousNode->rightChild = childNode;

        delete currentNode;
    }
    else { // taken from Chat-GPT (else statement) to handle nodes having 2 children
        Node* successorNode = currentNode->rightChild;
        Node* successorParent = currentNode;

        // Find the minimum node in the right subtree (successor)
        while (successorNode->leftChild != nullptr) {
            successorParent = successorNode;
            successorNode = successorNode->leftChild;
        }

        if (successorParent != currentNode)
            successorParent->leftChild = successorNode->rightChild;
        else
            successorParent->rightChild = successorNode->rightChild;

        // Replace the node's data with the successor's data
        currentNode->data = successorNode->data;

        delete successorNode;
    }
}

void BinaryTree::FixBalance() {
    // first, need to reach all the leaves that tree has
    int longestNode = GetTreeHeight(root);
    int shortestNode = GetShortestNode(root);


    // then calculate the each depth and compare them
    // if depth difference between nodes is more than 1,
    //..rebalancing operation is required
}

int BinaryTree::GetShortestNode(Node* currentNode) {

}

bool BinaryTree::Search(int key) {
    Node *currentNode = root;
    if (currentNode == nullptr) return false;

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