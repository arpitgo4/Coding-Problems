// Ordering Tasks (10305)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)

typedef pair<int,int> edge;
 
vector<vector<int>> G;
vector<int> vis, topo_sort;

void dfs(int u) {
    vis[u] = 1;

    for (int v : G[u]) {
        if (vis[v] == 0) {
            dfs(v);
        }
    }

    vis[u] = 2;
    topo_sort.push_back(u);
}

void solve(vector<edge>& edges, int V, int E) {
    G.assign(V+1, vector<int>());
    vis.assign(V+1, 0);
    topo_sort.clear();
    for (edge& e : edges) {
        int u = e.first, v = e.second;
        G[u].push_back(v);
    }

    for (int u = 1; u <= V; u++)
        if (vis[u] == 0)
            dfs(u);

    reverse(topo_sort.begin(), topo_sort.end());

    for (int u : topo_sort)
        cout << u << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    while (V != 0 && E != 0) {
        int u, v;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            edges[i] = { u, v };
        }

        solve(edges, V, E);

        cin >> V >> E;
    }

    return 0;
}