#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "Graph.h"
#include "ShortestPathSolver.h"

using namespace std;
using namespace std::chrono;

Graph generateRandomGraph(int V, double density) {
    Graph graph(V);
    srand(time(nullptr));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (i != j && rand() % 100 < density) {
                int weight = rand() % 100 + 1; 
                graph.addEdge(i, j, weight);
            }
        }
    }
    return graph;
}

double measureDijkstraTime(const Graph& graph, bool useMatrixRepresentation) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    ShortestPathSolver solver(graph);
    int start = 0;
    if (useMatrixRepresentation) {
        solver.dijkstra(start);
    } else {
        solver.dijkstra(start);
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    return time_span.count();
}

int main() {
    const int numVertices[] = {10, 50, 100, 500, 1000};
    const double densities[] = {0.25, 0.5, 0.75, 1.0}; 
    const int numInstances = 100;

    
    for (int i = 0; i < 5; ++i) {
        int V = numVertices[i];
        cout << "Liczba wierzchołków: " << V << endl;

        for (double density : densities) {
            cout << "Gęstość grafu: " << density << endl;

            double totalTimeMatrix = 0.0;
            double totalTimeList = 0.0;

            for (int j = 0; j < numInstances; ++j) {
                Graph randomGraph = generateRandomGraph(V, density);

                totalTimeMatrix += measureDijkstraTime(randomGraph, true);

                totalTimeList += measureDijkstraTime(randomGraph, false);
            }

            double avgTimeMatrix = totalTimeMatrix / numInstances;
            double avgTimeList = totalTimeList / numInstances;

            cout << "Średni czas dla macierzy sąsiedztwa: " << avgTimeMatrix << " sekund" << endl;
            cout << "Średni czas dla listy sąsiedztwa: " << avgTimeList << " sekund" << endl;
            cout << endl;
        }
    }

    return 0;
}

