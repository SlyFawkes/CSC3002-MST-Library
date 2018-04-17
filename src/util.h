

#ifndef SOLVINGLIBRARY_UTIL_H
#define SOLVINGLIBRARY_UTIL_H 1


#include <vector>

std::vector<int>* getTreeContaining(int nodeId, std::vector< std::vector<int> >* graphNodes, int* position) {
    std::vector<int>* graphNode;
    // For every vector in graphNodes select the one at position i
    for (unsigned long i = 0; i < graphNodes->size(); i++) {
        graphNode = &graphNodes->at(i);
        // For each vector check to see if it contains the integer nodeId
        for (unsigned long j = 0; j < graphNode->size(); j++) {
            if(graphNode->at(j) == nodeId) {
                // If it contains nodeId return the vector and set the position
                *position = static_cast<int>(i);
                return &graphNodes->at(i);
            }
        }
    }
}

bool doesTreeContain(int nodeId, std::vector<int>* tree) {
    // Check each item in vector for nodeId
    for(unsigned long i = 0; i < tree->size(); i++) {
        if(tree->at(i) == nodeId) {
            // If nodeId is found return true
            return true;
        }
    }
    // If the loop ends it means nodeId was not contained in the vector
    return false;
}

#endif //SOLVINGLIBRARY_UTIL_H
