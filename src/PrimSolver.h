
#ifndef SOLVINGLIBRARY_PRIMSOLVER_H
#define SOLVINGLIBRARY_PRIMSOLVER_H 1

#include "DataStructures/CSRGraph.h"
#include "DataStructures/Edge.h"
#include "Solver.h"


class PrimSolver : public Solver {
public:
//    CSRGraph* graph;
    explicit PrimSolver(CSRGraph* graph);
    Edge* solve(Edge* mstEdges) override;
};


#endif //SOLVINGLIBRARY_PRIMSOLVER_H
