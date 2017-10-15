
#include "FibonacciHeap.h"

FibonacciHeap :: FibonacciHeap() {
    nodeAmount = 0;
    minimumNode = nullptr;
}

Node FibonacciHeap::getMin() {
    return *minimumNode;
}

void FibonacciHeap::insert(Node* node) {
    node->degree = 0;
    node->parent = nullptr;
    node->child = nullptr;
    node->marked = false;
    if (minimumNode == nullptr) {
        //TODO possibly remove?
        node->left = nullptr;
        node->right = nullptr;
        minimumNode = node;
    } else {
        if (node->key < minimumNode->key) {
            node->left = minimumNode;
            node->right = minimumNode->right;
            minimumNode = node;
        }
    }
    this->nodeAmount++;
}

void FibonacciHeap::fibHeapUnion(FibonacciHeap heap) {
    if (minimumNode == nullptr) {
        minimumNode = heap.minimumNode;
    } else if (heap.minimumNode == nullptr) {
        return;
    } else {
        Node* currentHeapTail = minimumNode->left;
        Node* joiningHeapTail = heap.minimumNode->left;

        minimumNode->left = joiningHeapTail;
        currentHeapTail->right = heap.minimumNode;
        heap.minimumNode->left = currentHeapTail;
        joiningHeapTail->right = minimumNode;

        if (heap.minimumNode->key < minimumNode->key) {
            minimumNode = heap.minimumNode;
        }
    }

    nodeAmount = nodeAmount + heap.nodeAmount;
}

Node* FibonacciHeap::extractMin() {
    Node* extractedNode = minimumNode;

    if (extractedNode != nullptr && extractedNode->child != nullptr) {
        Node *currentChild = extractedNode->child;
        for (int i = 0; i < extractedNode->degree; i++) {
            currentChild->parent = nullptr;
            currentChild = currentChild->right;
        }
        Node *currentRootList = extractedNode->left;
        Node *childList = currentChild->left;

        extractedNode->left = childList;
        currentRootList->right = currentChild;
        currentChild->left = currentRootList;
        childList->right = extractedNode;

        //Remove extracted node from root list
        extractedNode->left->right = extractedNode->right;
        extractedNode->right->left = extractedNode->left;

        if (extractedNode == extractedNode->right) {
            minimumNode = nullptr;
        } else {
            minimumNode = extractedNode->right;
            consolidate();
        }
        nodeAmount--;
    }
    return extractedNode;
}

