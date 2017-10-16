
#ifndef SOLVINGLIBRARY_FIBONACCIHEAP_H
#define SOLVINGLIBRARY_FIBONACCIHEAP_H


#include "Node.h"

class FibonacciHeap {
public:
    int nodeAmount;
    Node* minimumNode;

    FibonacciHeap();
    void insert(Node* node);
    Node getMin();
    void fibHeapUnion(FibonacciHeap heap);
    void consolidate();
    Node* extractMin();
    void link(Node* nodeA, Node* nodeB);
    void decreaseKey(Node* node, int key);
    void cut(Node* child, Node* parent);
    void cascadeCut(Node* node);
};


#endif //SOLVINGLIBRARY_FIBONACCIHEAP_H
