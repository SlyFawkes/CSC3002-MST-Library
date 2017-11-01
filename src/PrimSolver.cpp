
#include <climits>
#include "PrimSolver.h"
#include "DataStructures/FibonacciHeap.h"


struct Edge {
    int nodeA;
    int nodeB;
    int weight;
    Edge(int nodeA, int nodeB, int weight) {
        this->nodeA = nodeA;
        this->nodeB = nodeB;
        this->weight = weight;
    }
};


PrimSolver::PrimSolver(CSRGraph* graph) {
    this->graph = graph;
}

CSRGraph PrimSolver::solve() {

//    int nodeMinEdgeWeight[graph->numberOfNodes];
    int nodeClosestAvailableNeighbour[graph->numberOfNodes];

    FibonacciHeap* heap = new FibonacciHeap();

    Node* heapNodes[graph->numberOfNodes];
    for (int i=0; i < graph->numberOfNodes; i++) {
//        nodeMinEdgeWeight[i] = INT_MAX;
        heapNodes[i] = new Node(i, INT_MAX);
        nodeClosestAvailableNeighbour[i] = -1;
        heap->insert(heapNodes[i]);
    }

    bool mstNodes[graph->numberOfNodes];
    Edge* mstEdges[graph->numberOfNodes - 1];


    for (int i=0; i < graph->numberOfNodes; i++) {
        Node* nextNode = heap->extractMin();
        int nodeId = nextNode->id;

        if (!mstNodes[nodeId] && nodeClosestAvailableNeighbour[nodeId] != -1) {
            mstEdges[i] = new Edge(nodeId, nodeClosestAvailableNeighbour[nodeId], graph->weightsList[nodeId]);

            for (int j = graph->nodeList[nodeId]; j < graph->nodeList[nodeId + 1]; j++) {
                if (graph->weightsList[j] < heapNodes[graph->edgeList[j]]->key) {
                    heap->decreaseKey(heapNodes[graph->edgeList[j]], graph->weightsList[j]);
                    nodeClosestAvailableNeighbour[graph->edgeList[j]] = nextNode->id;
                }
            }
        }
        mstNodes[nextNode->id] = true;
    }


    return *new CSRGraph();
}
