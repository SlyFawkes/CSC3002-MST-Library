//
// Created by dan on 13/10/17.
//

#ifndef SOLVINGLIBRARY_NODE_H
#define SOLVINGLIBRARY_NODE_H


class Node {
public:
    int degree;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    bool marked;
    int key;

    explicit Node(int key);

};


#endif //SOLVINGLIBRARY_NODE_H
