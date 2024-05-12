#ifndef SHORTESTPATHSOLVER_H
#define SHORTESTPATHSOLVER_H

#include <vector>
#include "Graph.h"


class ShortestPathSolver {
private:
    const Graph& graph;

public:
    ShortestPathSolver(const Graph& _graph);
    std::vector<int> dijkstra(int start) const;
    std::vector<int> bellmanFord(int start) const;
};

#endif

