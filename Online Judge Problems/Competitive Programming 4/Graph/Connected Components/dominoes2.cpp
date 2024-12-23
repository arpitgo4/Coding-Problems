// dominoes2 (https://open.kattis.com/problems/dominoes2)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
typedef pair<int,int> edge;

vector<vector<int>> G;
vector<int> vis;

void dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) {
        if (vis[v] == 0)
            dfs(v);
    }

    vis[u] = 2;
}

void build_graph(vector<edge>& edges, int E, int V) {
    G.assign(V+1, vector<int>());
    vis.assign(V+1, 0);
    for (auto& [u, v] : edges)
        G[u].push_back(v);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int V, E, Q;
        cin >> V >> E >> Q;
        
        int u, v;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            edges[i] = { u, v };
        }

        build_graph(edges, E, V);

        int q;
        for (int i = 0; i < Q; i++) {
            cin >> q;
            dfs(q);
        }
        
        int count = 0;
        for (int u = 1; u <= V; u++)
            if (vis[u] != 0)
                count++;

        cout << count << endl;
    }
    
    return 0;
}