int par[MAXN], Size[MAXN];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        Size[i] = 1;
    }
}

int getPar(int u)
{
    return par[u] == u ? u : par[u] = getPar(par[u]);
}

bool Union(int u, int v)
{
    u = getPar(u);
    v = getPar(v);

    if (u != v)
    {
        if (Size[v] > Size[u])
            swap(u, v);

        par[v] = u;
        Size[u] += Size[v];
        return 1;
    }

    return 0;
}

int getSize(int u)
{
    return Size[getPar(u)];
}