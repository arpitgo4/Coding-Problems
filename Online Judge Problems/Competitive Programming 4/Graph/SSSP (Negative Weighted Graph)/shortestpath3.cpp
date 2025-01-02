// shortestpath3 (https://open.kattis.com/problems/shortestpath3)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
 
using namespace std;
 
// Time: O(V * E)
// Space: O(V + E)
 
#define INF INT_MAX
#define NEG_INF INT_MIN

typedef long long ll;
typedef tuple<int,int,int> edge;
typedef pair<int,ll> graph_edge;

vector<vector<graph_edge>> G;
vector<ll> dist;
vector<int> vis;

void dfs(int u) {
    vis[u] = 1;
    dist[u] = NEG_INF;

    for (auto& [v, w] : G[u]) {
        if (vis[v] == 0 && dist[v] != NEG_INF) {
            dfs(v);
        }
    }

    vis[u] = 2;
}

void bellman_ford_sssp(vector<edge>& edges, int E, int V, int src) {
    dist[src] = 0;

    for (int i = 0; i < V-1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            dfs(u);
            dfs(v);
        }
    }
}

void solve(vector<edge>& edges, int E, int V, int src) {
    G.assign(V+1, vector<graph_edge>());
    dist.assign(V+1, INF);
    vis.assign(V+1, 0);

    for (auto& [u, v, w] : edges) {
        G[u].push_back({ v, w });
    }

    bellman_ford_sssp(edges, E, V, src);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E, Q, src;
    cin >> V >> E >> Q >> src;
    
    while (V != 0) {
        int u, v; ll w;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            edges[i] = { u, v, w };
        }
    
        solve(edges, E, V, src);

        for (int i = 0; i < Q; i++) {
            cin >> u;

            if (dist[u] == INF)
                cout << "Impossible" << endl;
            else if (dist[u] == NEG_INF)
                cout << "-Infinity" << endl;
            else cout << dist[u] << endl;
        }

        cin >> V >> E >> Q >> src;
    }
    
    return 0;
}