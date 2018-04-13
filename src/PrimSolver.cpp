
#include <climits>
#include "PrimSolver.h"
#include "DataStructures/FibonacciHeap.h"



//TODO remove graph from constructor only pass in when needed, one prim solver can solve many graphs
PrimSolver::PrimSolver(CSRGraph* graph) {
    this->graph = graph;
}

Edge* PrimSolver::solve(Edge* mstEdges) {

    int nodeClosestAvailableNeighbour[graph->numberOfNodes];

    FibonacciHeap heap = FibonacciHeap();

    Node* heapNodes[graph->numberOfNodes];
    for (int i=0; i < graph->numberOfNodes; i++) {
        heapNodes[i] = new Node(i, INT_MAX);
        nodeClosestAvailableNeighbour[i] = -1;
        heap.insert(heapNodes[i]);
    }

    bool mstNodes[graph->numberOfNodes] = {};


    Node* firstNode = heap.extractMin();
    int firstNodeId = firstNode->id;
    for (int j = graph->nodeList[firstNodeId]; j < graph->nodeList[firstNodeId + 1]; j++) {
        if (graph->weightsList[j] < heapNodes[graph->edgeList[j]]->key) {
            heap.decreaseKey(heapNodes[graph->edgeList[j]], graph->weightsList[j]);
            nodeClosestAvailableNeighbour[graph->edgeList[j]] = firstNodeId;
        }
    }
    mstNodes[firstNodeId] = true;

    for (int i=0; i < graph->numberOfNodes - 1; i++) {
        Node* nextNode = heap.extractMin();
        int nodeId = nextNode->id;

        if (!mstNodes[nodeId]) {
            mstEdges[i] = Edge(nodeId, nodeClosestAvailableNeighbour[nodeId], nextNode->key);

            for (int j = graph->nodeList[nodeId]; j < graph->nodeList[nodeId + 1]; j++) {
                if (graph->weightsList[j] < heapNodes[graph->edgeList[j]]->key && heapNodes[graph->edgeList[j]]->inHeap) {
                    heap.decreaseKey(heapNodes[graph->edgeList[j]], graph->weightsList[j]);
                    nodeClosestAvailableNeighbour[graph->edgeList[j]] = nextNode->id;
                }
            }
        }
        mstNodes[nextNode->id] = true;
    }


    return mstEdges;
}
