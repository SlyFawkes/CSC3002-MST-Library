

#include <cstdio>
#include "KruskalSolver.h"
#include "DataStructures/FibonacciHeap.h"
#include "util.h"


/**
 * Constructor, takes in the graph which it can determine the MST for.
 *
 * @param graph A pointer to a CSR representation of the graph
 */
KruskalSolver::KruskalSolver(CSRGraph* graph) {
    this->graph = graph;
}


/**
 * The main method which determines the minimum spanning tree for a graph.
 *
 * @param mstEdges Buffer in which to store the edges in the MST
 * @return The edges contained within the MST
 */
Edge* KruskalSolver::solve(Edge *mstEdges) {
    FibonacciHeap heap = FibonacciHeap();

    for(int nodeId = 0; nodeId < graph->numberOfNodes; nodeId++) {

        for (int j = graph->nodeList[nodeId]; j < graph->nodeList[nodeId + 1]; j++) {
            if(nodeId < graph->edgeList[j]) {
                heap.insert(new Node(nodeId, graph->weightsList[j], nodeId, graph->edgeList[j]));
            }
        }
    }


    std::vector< std::vector<int> > graphNodes;
    for(int i = 0; i < graph->numberOfNodes; i++) {
        std::vector<int> tree;
        tree.push_back(i);
        graphNodes.push_back(tree);
    }

    int count = 0;
    while(graphNodes.size() > 1) {
        Node smallestEdge = *heap.extractMin();
        int position;
        std::vector<int>* tree = getTreeContaining(smallestEdge.vertexA, &graphNodes, &position);
        if(!doesTreeContain(smallestEdge.vertexB, tree)) {
            std::vector<int>* tree2 = getTreeContaining(smallestEdge.vertexB, &graphNodes, &position);
            tree->insert(tree->end(), tree2->begin(), tree2->end());
            graphNodes.erase(graphNodes.begin() + position);
            mstEdges[count] = Edge(smallestEdge.vertexA, smallestEdge.vertexB, smallestEdge.key);
            count++;
        }
    }


    return mstEdges;
}


