#include <iostream>
#include <vector>
#include <algorithm>
#include "kruskal.h"

using namespace std;

/**
 * @brief Finds the set that an element belongs to using path compression.
 * 
 * @param subsets Vector of subsets representing the disjoint sets.
 * @param i The index of the element to find the set for.
 * @return int The root of the set that the element belongs to.
 */
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

/**
 * @brief Unions two sets using union by rank.
 * @brief Rank is used to optimize the union operation in disjoint set data structure.
 * It represents the depth of a tree in the disjoint set forest.
 * By always attaching the smaller tree under the root of the larger tree,
 * we can keep the tree flatter, and thus operations like find() are more efficient.
 * 
 * @param subsets Vector of subsets representing the disjoint sets.
 * @param x The first set root.
 * @param y The second set root.
 */
void unite(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

/**
 * @brief Implements Kruskal's algorithm to find the minimum spanning tree of a graph.
 * @brief The minimum spanning tree (MST) of a connected, undirected graph is a subgraph that is a tree, 
 * connects all the vertices together, and has the minimum total edge weight among all such trees.
 *
 * @param edges Vector of edges representing the graph.
 * @param V Number of vertices in the graph.
 * @return vector<Edge> Vector of edges representing the minimum spanning tree.
 *
 * @note Time Complexity: O(E log E) or O(E log V). Sorting of edges takes O(E log E). 
 * After sorting, we iterate through all edges, and the find and union operations take O(log V) time.
 * In the worst case, we iterate over each edge, leading to O(E log V) complexity for this part.
 * Space Complexity: O(V + E) due to storing the edges in the result vector and subsets vector. 
 * The space to store the subsets is O(V) and for result vector is O(E).
 */
vector<Edge> kruskal(vector<Edge>& edges, int V) {
    vector<Edge> result;
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<Subset> subsets(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0;
    int i = 0;
    while (e < V - 1 && i < edges.size()) {
        Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            unite(subsets, x, y);
            e++;
        }
    }
    return result;
}
