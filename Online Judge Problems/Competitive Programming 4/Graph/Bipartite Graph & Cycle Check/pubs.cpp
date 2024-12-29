// pubs (https://open.kattis.com/problems/pubs?tab=metadata)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
typedef pair<int,int> edge;

vector<vector<int>> G;
vector<int> vis, color;

void dfs(int u, int c) {
    vis[u] = 1;
    color[u] = c;

    for (int v : G[u]) {
        if (vis[v] == 0) {
            dfs(v, (c+1) % 2);
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

    for (int u = 1; u <= V; u++) {
        if (vis[u] == 0) {
            dfs(u, 0);
        }
    }

    bool can_solve = true;
    vector<string> A(V+1);
    for (int u = 1; u <= V; u++) {
        bool valid = false;
        if (color[u] == 0) {                                // pub
            for (int v : G[u]) {
                if (color[v] == 1) {
                    valid = true;
                }
            }
        } else {
            for (int v : G[u]) {
                if (color[v] == 0) {
                    valid = true;
                }
            }
        }

        if (valid) {
            A[u] = (color[u] == 0 ? "pub" : "house");
        } else {
            can_solve = false;
        }
    }

    if (!can_solve) {
        cout << "Impossible" << endl;
    } else {
        for (int u = 1; u <= V; u++)
            cout << A[u] << " ";
        cout << endl;
    }
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