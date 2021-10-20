#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 15;
using ll = long long int;


int n, m; // The number of nodes, edges.
int par[N]; // par[v] : holds the parent of "v" in the shortest path the source to node "v".
ll dist[N]; // dist[v] : holds the shortest distance between the source and node "v".
vector<pair<int, ll>> adj[N]; // The graph adjacency list.

void dijsktra(int u, ll c = 0) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
  pq.push({0, u});


  memset(par, -1, sizeof(par));
  fill(dist, dist + N, 1e17);

  dist[u] = 0;
  while (!pq.empty()) {
    c = pq.top().first;
    u = pq.top().second;
    pq.pop();

    if (dist[u] < c) continue;

    for (auto e : adj[u]) {
      int to = e.first;
      int cst = e.second;

      if (dist[to] > c + cst) {
        par[to] = u;
        dist[to] = c + cst;
        pq.push({dist[to], to});
      }
    }
  }
}
