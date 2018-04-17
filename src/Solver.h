//
// Created by dan on 17/04/18.
//

#ifndef SOLVINGLIBRARY_SOLVER_H
#define SOLVINGLIBRARY_SOLVER_H


#include "DataStructures/CSRGraph.h"
#include "DataStructures/Edge.h"

class Solver {
public:
    virtual ~Solver() = default;
    CSRGraph* graph{};
    virtual Edge* solve(Edge* mstEdges) = 0;
};


#endif //SOLVINGLIBRARY_SOLVER_H
