
#ifndef SOLVINGLIBRARY_FIBONACCIHEAP_H
#define SOLVINGLIBRARY_FIBONACCIHEAP_H 1


#include "Node.h"

class FibonacciHeap {
public:
    int nodeAmount;
    Node* minimumNode;

    FibonacciHeap();
    void insert(Node* node);
    Node* getMin();
    Node* extractMin();
    void decreaseKey(Node* node, int key);
    void fibHeapUnion(FibonacciHeap heap);

private:
    void link(Node* nodeA, Node* nodeB);
    void consolidate();
    void cut(Node* child, Node* parent);
    void cascadeCut(Node* node);
};


#endif //SOLVINGLIBRARY_FIBONACCIHEAP_H
