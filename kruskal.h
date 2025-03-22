#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(std::vector<Subset>& subsets, int i);
void unite(std::vector<Subset>& subsets, int x, int y);
std::vector<Edge> kruskal(std::vector<Edge>& edges, int numVertices);

#endif