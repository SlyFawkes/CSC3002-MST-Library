

#ifndef SOLVINGLIBRARY_UTIL_H
#define SOLVINGLIBRARY_UTIL_H 1


#include <vector>

std::vector<int>* getTreeContaining(int nodeId, std::vector< std::vector<int> >* graphNodes, int* position) {
    std::vector<int>* graphNode;
    for (int i = 0; i < graphNodes->size(); i++) {
        graphNode = &graphNodes->at(i);
        for (int j = 0; j < graphNode->size(); j++) {
            if(graphNode->at(j) == nodeId) {
                *position = i;
                return &graphNodes->at(i);
            }
        }
    }
}

bool doesTreeContain(int nodeId, std::vector<int>* tree) {
    for(unsigned long i = 0; i < tree->size(); i++) {
        if(tree->at(i) == nodeId) {
            return true;
        }
    }
    return false;
}

#endif //SOLVINGLIBRARY_UTIL_H
