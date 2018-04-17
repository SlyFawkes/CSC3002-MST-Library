
#ifndef SOLVINGLIBRARY_NODE_H
#define SOLVINGLIBRARY_NODE_H 1

#include <stddef.h>

class Node {
public:
    size_t id;
    int degree;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    bool marked;
    int key;
    bool inHeap;
    size_t vertexA;
    size_t vertexB;

    explicit Node(size_t id, int key);
    explicit Node(size_t id, int key, size_t vertexA, size_t vertexB);

};


#endif //SOLVINGLIBRARY_NODE_H
