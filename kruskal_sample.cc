#include "kruskal.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Edge> edges = {
        {0, 1, 4}, {0, 7, 8},
        {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 5, 4}, {2, 8, 2},
        {3, 4, 9}, {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1}, {6, 8, 6},
        {7, 8, 7}
    };

    std::vector<Edge> result = kruskal(edges, 9);
    std::cout << "Edges in the Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : result) {
        std::cout << edge.src << " - " << edge.dest << " : " << edge.weight << std::endl;
    }
    return 0;
}
