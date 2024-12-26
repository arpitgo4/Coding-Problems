// hoppers (https://open.kattis.com/problems/hoppers)
 
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
        if (vis[v] == 0) {                                         // tree-edge
            dfs(v, (c+1) % 2);
        } else if (color[u] == color[v]) {                         // back-edge/bi-directional edge or cross-edge
            is_bp_graph = false;
        }
    }

    vis[u] = 2;
}

void solve(vector<edge>& edges, int E, int V) {
    G.assign(V+1, vector<int>());
    vis.assign(V+1, 0);
    color.assign(V+1, -1);
    for (auto& [u, v] : edges) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int count = 0, nbp_count = 0;
    for (int u = 1; u <= V; u++) {
        if (vis[u] == 0) {
            is_bp_graph = true;
            count++;
            dfs(u, 0);

            if (!is_bp_graph) {
                nbp_count++;
            }
        }
    }

    cout << (nbp_count > 0 ? count-1 : count) << endl;
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