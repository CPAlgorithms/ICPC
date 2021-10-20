#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, dis[N], par[N];
vector<int> edges[N];

vector<int> edges[N];
void bfs(int u) {
    queue<int> q;
    q.push(u);

    memset(par, -1, sizeof(par));
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int v : edges[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}
