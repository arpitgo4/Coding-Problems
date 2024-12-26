// UVa 10004 - Bicoloring (https://onlinejudge.org/external/100/10004.pdf)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
typedef pair<int,int> edge;

vector<vector<int>> G;
vector<int> vis, color;

bool is_bp_graph;

void dfs(int u, int c) {
    vis[u] = 1;
    color[u] = c;

    for (int v : G[u]) {
        if (vis[v] == 0) {
            dfs(v, (c+1) % 2);
        } else if (color[u] == color[v]) {                             // vis[v] == 1 || vis[v] == 2
            is_bp_graph = false;
            return;
        }
    }

    vis[u] = 2;
}

void solve(vector<edge>& edges, int E, int V) {
    G.assign(V+1, vector<int>());
    vis.assign(V+1, 0);
    color.assign(V+1, -1);
    is_bp_graph = true;

    int u, v;
    for (auto& edge : edges) {
        u = edge.first;
        v = edge.second;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(0, 0);

    cout << (is_bp_graph ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V;

    while (V > 0) {
        cin >> E;

        int u, v;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            edges[i] = { u, v };
        }

        solve(edges, E, V);

        cin >> V;
    }
    
    return 0;
}