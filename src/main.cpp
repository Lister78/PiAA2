#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "Graph.h"
#include "ShortestPathSolver.h"

using namespace std;
using namespace std::chrono;

// Funkcja generująca losowy graf o określonej liczbie wierzchołków i gęstości
Graph generateRandomGraph(int V, double density) {
    Graph graph(V);
    srand(time(nullptr));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (i != j && rand() % 100 < density) {
                int weight = rand() % 100 + 1; // Losowa waga krawędzi (1-100)
                graph.addEdge(i, j, weight);
            }
        }
    }
    return graph;
}

// Funkcja mierząca czas wykonania algorytmu Dijkstry dla danego grafu i reprezentacji grafu
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
    const double densities[] = {0.25, 0.5, 0.75, 1.0}; // Gęstości grafu
    const int numInstances = 100; // Liczba instancji dla każdej kombinacji

    // Pętle dla różnych liczb wierzchołków i gęstości grafu
    for (int i = 0; i < 5; ++i) {
        int V = numVertices[i];
        cout << "Liczba wierzchołków: " << V << endl;

        for (double density : densities) {
            cout << "Gęstość grafu: " << density << endl;

            double totalTimeMatrix = 0.0;
            double totalTimeList = 0.0;

            // Pętle dla liczby instancji
            for (int j = 0; j < numInstances; ++j) {
                Graph randomGraph = generateRandomGraph(V, density);

                // Pomiar czasu dla macierzy sąsiedztwa
                totalTimeMatrix += measureDijkstraTime(randomGraph, true);

                // Pomiar czasu dla listy sąsiedztwa
                totalTimeList += measureDijkstraTime(randomGraph, false);
            }

            // Obliczanie średnich czasów wykonania dla obu reprezentacji grafu
            double avgTimeMatrix = totalTimeMatrix / numInstances;
            double avgTimeList = totalTimeList / numInstances;

            // Wyświetlanie wyników
            cout << "Średni czas dla macierzy sąsiedztwa: " << avgTimeMatrix << " sekund" << endl;
            cout << "Średni czas dla listy sąsiedztwa: " << avgTimeList << " sekund" << endl;
            cout << endl;
        }
    }

    return 0;
}

