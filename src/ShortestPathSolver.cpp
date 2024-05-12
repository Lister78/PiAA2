#include "ShortestPathSolver.h"
#include <iostream>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

ShortestPathSolver::ShortestPathSolver(const Graph& _graph) : graph(_graph) {}

std::vector<int> ShortestPathSolver::dijkstra(int start) const {
    int V = graph.getVertices();
    std::vector<int> dist(V, INF);
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (const auto& edge : graph.getNeighbors(u)) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

std::vector<int> ShortestPathSolver::bellmanFord(int start) const {
    int V = graph.getVertices();
    std::vector<int> dist(V, INF);
    dist[start] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (const auto& edge : graph.getNeighbors(u)) {
                int v = edge.to;
                int w = edge.weight;

                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int u = 0; u < V; ++u) {
        for (const auto& edge : graph.getNeighbors(u)) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                std::cout << "Graf zawiera cykl o koszcie ujemnym!" << std::endl;
                return std::vector<int>();
            }
        }
    }

    return dist;
}

