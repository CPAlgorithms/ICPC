#include <bits/stdc++.h>

using namespace std;
const int N = 2501;
using ll = long long int;

struct edge {
  int a, b, cost;

  edge() {}

  edge(int _a, int _b, int _c) : a(_a), b(_b), cost(_c) {}
};

int n, m;
int par[N];
ll dist[N];
vector<edge> adj;


int bellman(int u) {
  memset(par, -1, sizeof(par));
  fill(dist, dist + N, 1e17);

  int x;
  dist[u] = 0;

  for (int i = 0; i < n; i++) {
    x = -1;
    bool any = true;
    for (auto e : adj) {
      if (dist[e.a] + e.cost < dist[e.b]) {
        x = e.b;
        any = false;
        par[e.b] = e.a;
        dist[e.b] = dist[e.a] + e.cost;
      }
    }
    if (any) break; // no useful work to do
  }

  return x;
}
