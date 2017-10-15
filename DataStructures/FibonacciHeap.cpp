
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

