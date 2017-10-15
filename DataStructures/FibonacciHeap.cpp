
#include "FibonacciHeap.h"
#include <cmath>

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

Node* FibonacciHeap::extractMin() {
    Node* extractedNode = minimumNode;

    if (extractedNode != nullptr && extractedNode->child != nullptr) {
        Node *currentChild = extractedNode->child;
        for (int i = 0; i < extractedNode->degree; i++) {
            currentChild->parent = nullptr;
            currentChild = currentChild->right;
        }
        Node *currentRootList = extractedNode->left;
        Node *childList = currentChild->left;

        extractedNode->left = childList;
        currentRootList->right = currentChild;
        currentChild->left = currentRootList;
        childList->right = extractedNode;

        //Remove extracted node from root list
        extractedNode->left->right = extractedNode->right;
        extractedNode->right->left = extractedNode->left;

        if (extractedNode == extractedNode->right) {
            minimumNode = nullptr;
        } else {
            minimumNode = extractedNode->right;
            consolidate();
        }
        nodeAmount--;
    }
    return extractedNode;
}

void FibonacciHeap::consolidate() {
    auto maxDegree = static_cast<int>(log(nodeAmount));
    Node* tempArray[maxDegree] = {};

    Node* currentRootNode = minimumNode;
    do {
        int degree = currentRootNode->degree;

        while (tempArray[degree] != nullptr) {
            Node* nodeWithIdenticalDegree = tempArray[degree];
            if (currentRootNode->key > nodeWithIdenticalDegree->key) {
                Node* temp = currentRootNode;
                currentRootNode = nodeWithIdenticalDegree;
                nodeWithIdenticalDegree = temp;
            }
            link(nodeWithIdenticalDegree, currentRootNode);
            tempArray[degree] = nullptr;
            degree++;
        }
        tempArray[degree] = currentRootNode;

        currentRootNode = currentRootNode->right;
    } while (currentRootNode != minimumNode);

    minimumNode = nullptr;

    for (int i = 0; i < maxDegree; i++) {
        if (tempArray[i] != nullptr) {
            if (minimumNode == nullptr) {
                minimumNode = tempArray[i];
            } else if (tempArray[i]->key < minimumNode->key){
                minimumNode = tempArray[i];
            }
        }
    }
}

void FibonacciHeap::link(Node* nodeA, Node *nodeB) {
    nodeA->parent = nodeB;
    nodeB->child = nodeA;
    nodeB->degree++;

    Node* tempNodeALeft = nodeA->left;
    Node* tempNodeBRight = nodeB->right;

    nodeA->left = nodeB->left;
    nodeA->right = nodeB->right;

    nodeB->left = tempNodeALeft;
    nodeB->right = tempNodeBRight;
    nodeA->marked = false;
}

void FibonacciHeap::decreaseKey(Node* node, int key) {
    if (key > node->key) {
        return;
    }

    node->key = key;
    Node* parent = node->parent;

    if (parent != nullptr && node->key < parent->key) {
        cut(node, parent);
        cascadeCut(parent);
    }
    if (node->key < minimumNode->key) {
        minimumNode = node;
    }
}

void FibonacciHeap::cut(Node* child, Node* parent) {
    if (child != child->right) {
        parent->child = child->right;
        child->left->right = child->right;
        child->right->left = child->left;
    } else {
        parent->child = nullptr;
    }
    child->parent = nullptr;
    child->marked = false;
    child->left = minimumNode;
    child->right = minimumNode->right;
    minimumNode->right->left = child;
    minimumNode->right = child;
}

void FibonacciHeap::cascadeCut(Node* node) {
    Node* parent = node->parent;
    if (parent != nullptr) {
        if (!node->marked) {
            node->marked = true;
        } else {
            cut(node, parent);
            cascadeCut(parent);
        }
    }
}





