

#ifndef SOLVINGLIBRARY_KRUSKALSOLVER_H
#define SOLVINGLIBRARY_KRUSKALSOLVER_H

#include <vector>
#include "DataStructures/Node.h"
#include "DataStructures/CSRGraph.h"
#include "DataStructures/Edge.h"
#include "Solver.h"

class KruskalSolver: public Solver {
public:
    explicit KruskalSolver(CSRGraph* graph);
    Edge* solve(Edge* mstEdges) override;
};


#endif //SOLVINGLIBRARY_KRUSKALSOLVER_H
