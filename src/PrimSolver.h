
#ifndef SOLVINGLIBRARY_PRIMSOLVER_H
#define SOLVINGLIBRARY_PRIMSOLVER_H 1

#include "DataStructures/CSRGraph.h"
#include "DataStructures/Edge.h"


class PrimSolver {
public:
    CSRGraph* graph;
    explicit PrimSolver(CSRGraph* graph);
    Edge* solve(Edge* mstEdges);
};


#endif //SOLVINGLIBRARY_PRIMSOLVER_H
