#include "kruskal.h"
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

void test_empty_graph() {
  cout << "Running test_empty_graph..." << endl;
  vector<Edge> edges;
  int num_vertices = 0;
  vector<Edge> mst = kruskal(edges, num_vertices);
  assert(mst.empty());
  cout << "test_empty_graph passed." << endl;
}

void test_single_edge() {
  cout << "Running test_single_edge..." << endl;
  vector<Edge> edges = {{0, 1, 5}};
  int num_vertices = 2;
  vector<Edge> mst = kruskal(edges, num_vertices);
  assert(mst.size() == 1);
  assert(mst[0].src == 0);  assert(mst[0].dest == 1);
  assert(mst[0].weight == 5);
  cout << "test_single_edge passed." << endl;
}

void test_multiple_edges() {
  cout << "Running test_multiple_edges..." << endl;
  vector<Edge> edges = {
      {0, 1, 10},
      {0, 2, 6},
      {0, 3, 5},
      {1, 3, 15},
      {2, 3, 4},
  };
  int num_vertices = 4; vector<Edge> mst = kruskal(edges, num_vertices);
  assert(mst.size() == 3);
  vector<Edge> expected_mst = {
      {2, 3, 4},
      {0, 3, 5},
      {0, 1, 10},
  };

  for (const auto &edge : mst) {
       bool found = false;
      for(auto e : expected_mst){ if (e.src == edge.src && e.dest == edge.dest && e.weight == edge.weight) found=true;}
      assert(found);
  }

    cout << "test_multiple_edges passed." << endl;
}

void test_disconnected_graph() {
  cout << "Running test_disconnected_graph..." << endl;
    vector<Edge> edges = {
        {0, 1, 1},
      {2, 3, 1},
    };
    int num_vertices = 4;
    vector<Edge> mst = kruskal(edges, num_vertices);
  assert(mst.size() == 2);
  cout << "test_disconnected_graph passed." << endl;
}

void test_example() {
  cout << "Running test_example..." << endl;
    vector<Edge> edges = {
      {0, 1, 4},
      {0, 7, 8},
      {1, 2, 8},
      {1, 7, 11},
      {2, 3, 7},
      {2, 8, 2},
      {2, 5, 4},
      {3, 4, 9},
      {3, 5, 14},
      {4, 5, 10},
      {5, 6, 2},
      {6, 7, 1},
      {6, 8, 6},
      {7, 8, 7},
    };
    int num_vertices = 9;
    vector<Edge> mst = kruskal(edges, num_vertices);
    int total_weight = 0;
  for (const auto &edge : mst) {
      total_weight += edge.weight;
    }
  assert(total_weight == 37);
  assert(mst.size() == 8);
    vector<Edge> expected_mst = {
        {6, 7, 1},
        {2, 8, 2},
        {5, 6, 2},
        {0, 1, 4},
        {2, 5, 4},
        {2, 3, 7},
        {0, 7, 8},
        {3, 4, 9},
    };

    for (const auto &edge : mst) {
        bool found = false;
        for(auto e : expected_mst){ if (e.src == edge.src && e.dest == edge.dest && e.weight == edge.weight) found=true;}
        assert(found);
    }
    cout << "test_example passed." << endl;
}

int main() {
  cout << "Starting Kruskal tests..." << endl;

  test_empty_graph();
  test_single_edge();
  test_multiple_edges();
  test_disconnected_graph();
  test_example();

  cout << "All Kruskal tests passed!" << endl;

  return 0;
}
