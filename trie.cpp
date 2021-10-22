const int MAXN = 2e6;
int trie[MAXN][26], m, endWord[MAXN];

void insert(const string &s)
{
    int u = 0;
    for (auto c : s)
    {
        trie[u][c - 'a'] = ++m;
        u = trie[u][c - 'a'];
    }
    endWord[u]++;
}

bool checkPrefix(const string &s)
{
    int u = 0;
    for (auto c : s)
    {
        if (trie[u][c - 'a'])
            u = trie[u][c - 'a'];
        else
            return 0;
    }

    return true;
}