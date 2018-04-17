

#ifndef SOLVINGLIBRARY_EDGE_H
#define SOLVINGLIBRARY_EDGE_H 1

struct Edge {
    int nodeA;
    int nodeB;
    int weight;
    Edge() {}
    Edge(int nodeA, int nodeB, int weight) {
        this->nodeA = nodeA;
        this->nodeB = nodeB;
        this->weight = weight;
    }

    inline bool operator==(const Edge& rhs) const {
        if (this->weight == rhs.weight) {
            return ((this->nodeA == rhs.nodeA && this->nodeB == rhs.nodeB) ||
                    this->nodeA == rhs.nodeB && this->nodeB == rhs.nodeA);
        }
    }
};

#endif //SOLVINGLIBRARY_EDGE_H
