#ifndef EDGE_H
#define EDGE_H

struct Edge {
    int from; 
    int to; 
    int weight; 
    Edge(int _from, int _to, int _weight);
};

#endif 

