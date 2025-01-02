// UVa 00558 - Wormholes (https://onlinejudge.org/external/5/558.pdf)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
 
using namespace std;
 
// Time: O(V * E)
// Space: O(V)
 
#define INF INT_MAX

typedef tuple<int,int,int> edge;

void solve(vector<edge>& edges, int E, int V) {
    vector<int> dist(V+1, INF);
    dist[0] = 0;

    int u, v, t;
    for (int i = 0; i < V-1; i++) {
        for (edge& edge : edges) {
            tie(u, v, t) = edge;
            if (dist[v] > dist[u] + t) {
                dist[v] = dist[u] + t;
            }
        }
    }

    bool edge_relaxed = false;
    for (edge& edge : edges) {
        tie(u, v, t) = edge;
        if (dist[v] > dist[u] + t) {
            dist[v] = dist[u] + t;
            edge_relaxed = true;
        }
    }

    cout << (edge_relaxed ? "possible" : "not possible") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int V, E;
        cin >> V >> E;
        
        int u, v, t;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> t;
            edges[i] = { u, v, t };
        }
    
        solve(edges, E, V);
    }
    
    return 0;
}