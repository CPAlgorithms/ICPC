#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MAXN = 2e5 + 5;

int n, m, timer, compNum[MAXN];
vector<int> adj[MAXN], revAdj[MAXN], finish;
vector<pair<int, int>> edges;
bool vis1[MAXN], vis2[MAXN];

void calcTimes(int node)
{
    if (vis1[node])
        return;
    vis1[node] = 1;
    timer++;

    for (auto i : adj[node])
        calcTimes(i);

    timer++;
    finish.push_back(node);
}

void calcComps(int node, int num)
{
    if (vis2[node])
        return;

    vis2[node] = 1;
    compNum[node] = num;

    for (auto i : revAdj[node])
        calcComps(i, num);
}

void init(int m)
{
    for (int i = 0, fr, to; i < m; i++)
    {
        cin >> fr >> to;
        edges.push_back({fr, to});
        adj[fr].push_back(to);
        revAdj[to].push_back(fr);
    }
}

void process()
{
    for (int i = 1; i <= n; i++)
    {
        calcTimes(i);
    }

    for (int i = finish.size() - 1, cnt = 1; i >= 0; i--)
    {
        if (!vis2[finish[i]])
            calcComps(finish[i], cnt++);
    }
}

int main()
{
    IO;
    cin >> n >> m;
    init(m);
    process();

    // Complete your code HERE!

    return 0;
}