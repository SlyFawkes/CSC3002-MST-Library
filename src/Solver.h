
#ifndef SOLVINGLIBRARY_SOLVER_H
#define SOLVINGLIBRARY_SOLVER_H 1


#include "DataStructures/CSRGraph.h"
#include "DataStructures/Edge.h"

class Solver {
public:
    virtual ~Solver() = default;
    CSRGraph* graph{};
    virtual Edge* solve(Edge* mstEdges) = 0;
};


#endif //SOLVINGLIBRARY_SOLVER_H
