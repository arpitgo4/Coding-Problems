// Cyclic Components (https://codeforces.com/problemset/problem/977/E)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
typedef pair<int,int> edge;

vector<vector<int>> G;
vector<int> vis;

int dfs(int u) {
    if (G[u].size() > 2 || G[u].size() < 2)
        return 0;

    vis[u] = 1;

    int flag = 1;
    for (int v : G[u]) {
        if (vis[v] == 0) {
            flag &= dfs(v);
        }
    }

    vis[u] = 2;

    return flag;
}

void solve(vector<edge>& edges, int E, int V) {
    G.assign(V+1, vector<int>());
    vis.assign(V+1, 0);
    for (auto& [u, v] : edges) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int count = 0;
    for (int u = 1; u <= V; u++) {
        if (vis[u] == 0)
            count += dfs(u);
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;
    
    int u, v;
    vector<edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        edges[i] = { u, v };
    }

    solve(edges, E, V);
    
    return 0;
}