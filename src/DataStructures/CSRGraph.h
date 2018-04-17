

#ifndef SOLVINGLIBRARY_CSRGRAPH_H
#define SOLVINGLIBRARY_CSRGRAPH_H 1

#include <cstddef>

struct CSRGraph {
    size_t numberOfNodes;
    size_t numberOfEdges;
    size_t* nodeList;
    size_t * edgeList;
    int * weightsList;
};

#endif //SOLVINGLIBRARY_CSRGRAPH_H
