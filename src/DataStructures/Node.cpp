
#include "Node.h"

/**
 * Constructor for a Node object.
 *
 * @param id Unique id of the node
 * @param key Value to sort the nodes by
 * @param vertexA Optional id of a graph vertex
 * @param vertexB Optional id of a graph vertex
 */
Node::Node(int id, int key, int vertexA, int vertexB) {
    this->id = id;
    this->key = key;
    this->degree = 0;
    this->parent = nullptr;
    this->child = nullptr;
    this->marked = false;
    this->left = this;
    this->right = this;
    this->inHeap = true;
    this->vertexA = vertexA;
    this->vertexB = vertexB;
}

/**
 * Constructor for a Node object.
 *
 * @param id Unique id of the node
 * @param key Value to sort the nodes by
 */
Node::Node(int id, int key) {
    this->id = id;
    this->key = key;
    this->degree = 0;
    this->parent = nullptr;
    this->child = nullptr;
    this->marked = false;
    this->left = this;
    this->right = this;
    this->inHeap = true;
    this->vertexA = {};
    this->vertexB = {};
}
