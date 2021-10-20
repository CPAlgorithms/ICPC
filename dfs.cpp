const int maxn = 1e5 + 15;
vi adj[maxn];
bool vis[maxn];

vi topoSort;


void dfs(int u){
  if(vis[u]) return;
  vis[u] = 1;
  
  for(auto v : adj[u]){
    dfs(v);
  }
}
