//
// Created by dan on 13/10/17.
//

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
};


#endif //SOLVINGLIBRARY_FIBONACCIHEAP_H
