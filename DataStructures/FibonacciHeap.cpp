
#include "FibonacciHeap.h"

FibonacciHeap :: FibonacciHeap() {
    nodeAmount = 0;
    minimumNode = nullptr;
}

void FibonacciHeap::insert(Node* node) {
    node->degree = 0;
    node->parent = nullptr;
    node->child = nullptr;
    node->marked = false;
    if (minimumNode == nullptr) {
        minimumNode = node;
    } else {
        if (node->key < minimumNode->key) {
            minimumNode = node;
        }
    }
    this->nodeAmount++;
}
