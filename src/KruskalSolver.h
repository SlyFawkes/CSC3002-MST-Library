

#ifndef SOLVINGLIBRARY_KRUSKALSOLVER_H
#define SOLVINGLIBRARY_KRUSKALSOLVER_H

#include <vector>
#include "DataStructures/Node.h"
#include "DataStructures/CSRGraph.h"
#include "DataStructures/Edge.h"

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
