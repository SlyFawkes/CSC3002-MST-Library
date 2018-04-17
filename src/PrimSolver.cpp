
#include <climits>
#include "PrimSolver.h"
#include "DataStructures/FibonacciHeap.h"


/**
 * Constructor, takes in the graph which it can determine the MST for.
 *
 * @param graph A pointer to a CSR representation of the graph
 */
PrimSolver::PrimSolver(CSRGraph* graph) {
    this->graph = graph;
}

/**
 * The main method which determines the minimum spanning tree for a graph.
 *
 * @param mstEdges Buffer in which to store the edges in the MST
 * @return The edges contained within the MST
 */
Edge* PrimSolver::solve(Edge* mstEdges) {

    int nodeClosestAvailableNeighbour[graph->numberOfNodes];

    FibonacciHeap heap = FibonacciHeap();

    Node* heapNodes[graph->numberOfNodes];
    // Set the key of each node to max int,
    // also set nearest neighbour to value indication none found yet
    for (int i=0; i < graph->numberOfNodes; i++) {
        heapNodes[i] = new Node(i, INT_MAX);
        nodeClosestAvailableNeighbour[i] = -1;
        heap.insert(heapNodes[i]);
    }

    bool mstNodes[graph->numberOfNodes] = {};

    // extract first node and note its id
    Node* firstNode = heap.extractMin();
    int firstNodeId = firstNode->id;

    // For every node connected to the first node update the key to that connected nodes new lowest value
    // also set each nearest neighbour to the one connected by the lowest weight so far
    for (size_t j = graph->nodeList[firstNodeId]; j < graph->nodeList[firstNodeId + 1]; j++) {
        if (graph->weightsList[j] < heapNodes[graph->edgeList[j]]->key) {
            heap.decreaseKey(heapNodes[graph->edgeList[j]], graph->weightsList[j]);
            nodeClosestAvailableNeighbour[graph->edgeList[j]] = firstNodeId;
        }
    }
    // Indicate that the first node has been added to the MST
    mstNodes[firstNodeId] = true;

    // Loop through the remaining nodes in the heap, extract the minimum node at each step
    for (int i=0; i < graph->numberOfNodes - 1; i++) {
        Node* nextNode = heap.extractMin();
        int nodeId = nextNode->id;

        // Skip the node if it's already in the MST
        if (!mstNodes[nodeId]) {
            mstEdges[i] = Edge(nodeId, nodeClosestAvailableNeighbour[nodeId], nextNode->key);

            // For every node connected to the current node update the key to that connected nodes new lowest value
            // also set each nearest neighbour to the one connected by the lowest weight so far
            for (size_t j = graph->nodeList[nodeId]; j < graph->nodeList[nodeId + 1]; j++) {
                if (graph->weightsList[j] < heapNodes[graph->edgeList[j]]->key && heapNodes[graph->edgeList[j]]->inHeap) {
                    heap.decreaseKey(heapNodes[graph->edgeList[j]], graph->weightsList[j]);
                    nodeClosestAvailableNeighbour[graph->edgeList[j]] = nextNode->id;
                }
            }
        }
        // Indicate the current node has now been added to the MST
        mstNodes[nextNode->id] = true;
    }


    return mstEdges;
}
