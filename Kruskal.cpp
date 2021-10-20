#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

using ll = long long int;

struct edge {
  ll weight{};
  int from{}, to{};

  edge() = default;

  edge(int f, int t, ll w) : from(f), to(t), weight(w) {}

  bool operator<(const edge &rhs) const {
    return (weight < rhs.weight);
  }
};

int n, m;
int par[N];
int rnk[N];

vector<edge> edges;

void init() {
  for (int i = 0; i < N; i++) {
    rnk[i] = 1;
    par[i] = i;
  }
}

int find(int u) {
  return (u == par[u]) ? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (rnk[v] > rnk[u]) {
    swap(u, v);
  }

  par[v] = u;
  rnk[u] += rnk[v];
}

ll kruskalMST() {
  init();
  sort(edges.begin(), edges.end());

  ll mn = 0LL;
  int cnt = 0;

  for (auto i : edges) {
    if (find(i.from) != find(i.to)) {
      cnt++;
      mn += i.weight;
      merge(i.from, i.to);
    }
  }

  if (cnt == n - 1) {
    return mn;
  } else {
    return -1;
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;

    edges.emplace_back(edge(u, v, c));
  }

  ll ret = kruskalMST();
  cout << ret << endl;
}
