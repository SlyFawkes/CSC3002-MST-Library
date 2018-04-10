

#ifndef SOLVINGLIBRARY_KRUSKALSOLVER_H
#define SOLVINGLIBRARY_KRUSKALSOLVER_H

#include <cstddef>
#include <vector>
#include "DataStructures/Node.h"

struct CSRGraph {
    size_t numberOfNodes;
    size_t numberOfEdges;
    int* nodeList;
    int* edgeList;
    int* weightsList;
};

struct Edge {
    int nodeA;
    int nodeB;
    int weight;
    Edge() {}
    Edge(int nodeA, int nodeB, int weight) {
        this->nodeA = nodeA;
        this->nodeB = nodeB;
        this->weight = weight;
    }

    inline bool operator==(const Edge& rhs) const {
        if (this->weight == rhs.weight) {
            return ((this->nodeA == rhs.nodeA && this->nodeB == rhs.nodeB) ||
                    this->nodeA == rhs.nodeB && this->nodeB == rhs.nodeA);
        }
    }
};

class KruskalSolver {
public:
    CSRGraph* graph;
    explicit KruskalSolver(CSRGraph* graph);
    Edge* solve(Edge* mstEdges);

private:
    std::vector<int>* getTreeContaining(int nodeId, std::vector< std::vector<int> >* graphNodes, int* position);
    bool doesTreeContain(int nodeId, std::vector<int>* tree);
    };


#endif //SOLVINGLIBRARY_KRUSKALSOLVER_H
