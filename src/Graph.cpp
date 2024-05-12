#include "Graph.h"

Graph::Graph(int _V) : V(_V), adjacencyList(_V) {}

void Graph::addEdge(int from, int to, int weight) {
    adjacencyList[from].push_back(Edge(from, to, weight));
}

int Graph::getVertices() const {
    return V;
}

const std::vector<Edge>& Graph::getNeighbors(int vertex) const {
    return adjacencyList[vertex];
}

