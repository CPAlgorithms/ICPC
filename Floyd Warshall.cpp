#include <bits/stdc++.h>

using namespace std;


const int N = 101;
const int OO = 1e9;
const double EPS = 1e-9;

int n, m;              // The number of nodes/edges.
int adj[N][N];      // The graph adjacency matrix.
int par[N][N];      // par[u][v] : holds the parent node of "v" in the shortest path from "u" to "v".

vector<int> path;

void init() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      adj[i][j] = (i == j ? 0 : OO);
      par[i][j] = i;
    }
  }
}

/**
 * Computes the shortest path between any pair of nodes in the graph
 * and updates the adjacency matrix in accordance by running Floyd Warshall's algorithm.
 * (i.e. All-Pair Shortest Path (APSP))
 *
 * Complexity: O(n^3)
 */
void floyd() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (adj[i][j] > adj[i][k] + adj[k][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
          par[i][j] = par[k][j];
        }
      }
    }
  }
}
