
#ifndef SOLVINGLIBRARY_PRIMSOLVER_H
#define SOLVINGLIBRARY_PRIMSOLVER_H 1

#include <cstddef>

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

class PrimSolver {
public:
    CSRGraph* graph;
    explicit PrimSolver(CSRGraph* graph);
    Edge* solve(Edge* mstEdges);

};


#endif //SOLVINGLIBRARY_PRIMSOLVER_H
