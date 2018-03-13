//
// Created by dan on 13/10/17.
//

#ifndef SOLVINGLIBRARY_NODE_H
#define SOLVINGLIBRARY_NODE_H 1


class Node {
public:
    int id;
    int degree;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    bool marked;
    int key;
    bool inHeap;

    explicit Node(int id, int key);

};


#endif //SOLVINGLIBRARY_NODE_H
