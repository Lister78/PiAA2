#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Edge.h"

class Graph {
private:
    int V; 
    std::vector<std::vector<Edge>> adjacencyList; 

public:
    Graph(int _V);
    void addEdge(int from, int to, int weight);
    int getVertices() const;
    const std::vector<Edge>& getNeighbors(int vertex) const;
};

#endif


