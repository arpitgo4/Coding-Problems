// shortestpath1 (https://open.kattis.com/problems/shortestpath1)
 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
 
// Time: O(ElogV)
// Space: O(V)

#define INF LLONG_MAX

typedef long long ll;
typedef tuple<int,int,ll> edge;
typedef pair<int,ll> graph_edge;
typedef pair<ll,int> state;

vector<vector<graph_edge>> G;
vector<int> vis;
vector<ll> dist;

void dijkstra(int src) {
    auto cmp = [&](const state& s1, const state& s2) {
        return s1.first > s2.first;
    };
    priority_queue<state, vector<state>, decltype(cmp)> pq(cmp);
    dist[src] = 0;
    pq.push({ dist[src], src });

    while (!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();

        if (vis[u] != 0)
            continue;
        vis[u] = 1;

        for (auto& [v, w] : G[u]) {
            if (vis[v] == 0 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}

void build_graph(vector<edge>& edges, int E, int V) {
    G.assign(V+1, vector<graph_edge>());
    vis.assign(V+1, 0);
    dist.assign(V+1, INF);
    for (auto& [u, v, w] : edges) {
        G[u].push_back({ v, w });
    }
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
    
        build_graph(edges, E, V);
        dijkstra(src);

        int q;
        for (int i = 0; i < Q; i++) {
            cin >> q;
            ll d = dist[q];
            if (d == INF)
                cout << "Impossible" << endl;
            else cout << d << endl;
        }
        cout << endl;

        cin >> V >> E >> Q >> src;
    }
    
    return 0;
}