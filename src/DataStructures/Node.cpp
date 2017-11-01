//
// Created by dan on 13/10/17.
//

#include "Node.h"

Node::Node(int id, int key) {
    this->id = id;
    this->key = key;
    this->degree = 0;
    this->parent = nullptr;
    this->child = nullptr;
    this->marked = false;
    this->left = this;
    this->right = this;
}
