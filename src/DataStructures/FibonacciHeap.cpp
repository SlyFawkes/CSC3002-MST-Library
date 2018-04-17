
#include "FibonacciHeap.h"

/**
 * Constructor, sets default values for publicly accessible values
 */
FibonacciHeap :: FibonacciHeap() {
    nodeAmount = 0;
    minimumNode = nullptr;
}

/**
 * Retrieve the minimum node without removing it from the heap.
 *
 * @return Pointer to the minimum node in the heap
 */
Node* FibonacciHeap::getMin() {
    return minimumNode;
}

/**
 * Insert the specified node into the heap.
 *
 * @param node A pointer to the node which is to be added to the heap.
 */
void FibonacciHeap::insert(Node* node) {
    node->degree = 0;
    node->parent = nullptr;
    node->child = nullptr;
    node->marked = false;
    if (minimumNode == nullptr) {
        minimumNode = node;
    } else {
        node->left = minimumNode;
        node->right = minimumNode->right;
        minimumNode->right->left = node;
        minimumNode->right = node;
        if (node->key < minimumNode->key) {
            minimumNode = node;
        }
    }
    this->nodeAmount++;
}

/**
 * Joins a second heap into the current heap.
 *
 * @param heap The heap that is to be added to the current heap.
 */
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

/**
 * Remove the minimum node from the heap and return it to the caller.
 *
 * @return A pointer to the extracted node.
 */
Node* FibonacciHeap::extractMin() {
    Node* extractedNode = minimumNode;

    if (extractedNode != nullptr) {
        if (extractedNode->child != nullptr) {
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
        }

        // Remove extracted node from root list
        extractedNode->left->right = extractedNode->right;
        extractedNode->right->left = extractedNode->left;

        if (extractedNode == extractedNode->right) {
            minimumNode = nullptr;
        } else {
            minimumNode = extractedNode->right;
            consolidate();
        }
        nodeAmount--;
        extractedNode->inHeap = false;
    }
    return extractedNode;
}

/**
 * Consolidates the root list, ensures every root has a unique degree value.
 */
void FibonacciHeap::consolidate() {
    int maxDegree = nodeAmount;
    Node* tempArray[maxDegree + 1] = {};

    Node* currentRootNode = minimumNode;
    int noRootNodes = 1;
    while (currentRootNode != minimumNode->left) {
        noRootNodes++;
        currentRootNode = currentRootNode->right;
    }

    Node* rootNodeList[noRootNodes];
    currentRootNode = minimumNode;
    for (int i = 0; i < noRootNodes; i++) {
        rootNodeList[i] = currentRootNode;
        currentRootNode = currentRootNode->right;
    }
    for (int i = 0; i < noRootNodes; i++) {
        currentRootNode = rootNodeList[i];
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

    }

    minimumNode = nullptr;

    for (int i = 0; i <= maxDegree; i++) {
        if (tempArray[i] != nullptr) {
            if (minimumNode == nullptr) {
                minimumNode = tempArray[i];
            } else if (tempArray[i]->key < minimumNode->key) {
                minimumNode = tempArray[i];
            }
        }
    }
}

/**
 *
 * Removes rootNode from the root list and makes it a child of newParent.
 * Increases degree of newParent and removes mark from rootNode.
 *
 * @param rootNode A pointer to the node being removed from the root list
 * @param newParent A pointer to the node which will be the parent of rootNode
 */
void FibonacciHeap::link(Node* rootNode, Node* newParent) {
    rootNode->parent = newParent;

    rootNode->left->right = rootNode->right;
    rootNode->right->left = rootNode->left;
    if (newParent->child == nullptr) {
        newParent->child = rootNode;
        rootNode->left = rootNode;
        rootNode->right = rootNode;
    } else {
        rootNode->left = newParent->child;
        rootNode->right = newParent->child->right;
        newParent->child->right->left = rootNode;
        newParent->child->right = rootNode;
    }
    newParent->degree++;
    rootNode->marked = false;
}

/**
 * Reduce the key of the referenced node to the new value if the new value is lesser than the nodes original key value.
 *
 * @param node A pointer to the node which is to have its key decreased
 * @param key The new value for the nodes key
 */
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

/**
 * Remove the node child from their parent and add them to the root list of nodes.
 *
 * @param child A pointer to the node to be removed from their parent node
 * @param parent The parent of the node that is being added to the root list
 */
void FibonacciHeap::cut(Node* child, Node* parent) {
    if (child != child->right) {
        parent->child = child->right;
        child->left->right = child->right;
        child->right->left = child->left;
        parent->degree--;
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

/**
 * Calls the cut method until it finds an unmarked node or a node in the root list.
 *
 * @param node A pointer to the node which is being checked whether or not it should be cut
 */
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





