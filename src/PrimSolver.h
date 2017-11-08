
#ifndef SOLVINGLIBRARY_PRIMSOLVER_H
#define SOLVINGLIBRARY_PRIMSOLVER_H

#include <cstddef>
#include "AbstractSolver.h"

struct CSRGraph {
    size_t numberOfNodes;
    size_t numberOfEdges;
    int* nodeList;
    int* edgeList;
    int* weightsList;
};

class PrimSolver {
public:
    CSRGraph* graph;
    explicit PrimSolver(CSRGraph* graph);
    CSRGraph solve();

};


#endif //SOLVINGLIBRARY_PRIMSOLVER_H
