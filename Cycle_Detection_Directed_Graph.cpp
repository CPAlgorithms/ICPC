#include <bits/stdc++.h>
using namespace std;
 
class Graph {
    int V;
    list<int>* adj;
 
public:
    Graph(int V); 
    void addEdge(int u, int v);
 
    bool isCycle();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
 
bool Graph::isCycle()
{
    
    vector<int> in_degree(V, 0);
 
    for (int u = 0; u < V; u++) {
        for (auto v : adj[u])
            in_degree[v]++;
    }
 
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
 
    int cnt = 0;
 
    
    vector<int> top_order;
 
    while (!q.empty()) {
 
        int u = q.front();
        q.pop();
        top_order.push_back(u);
 
        
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
 
            if (--in_degree[*itr] == 0)
                q.push(*itr);
 
        cnt++;
    }
 
    if (cnt != V)
        return true;
    else
        return false;
}
 
int main(){

    int vertices;
    cin >> vertices;
    Graph g(vertices);

    int edges;
    cin >> edges;
    int x, y;

    while(edges--){
        cin >> x >> y;
        g.addEdge(x, y);
    }

    cout << "Does the input graph has cycle : ";
    if(g.isCycle()){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}