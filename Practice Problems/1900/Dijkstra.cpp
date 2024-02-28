// Dijkstra (https://codeforces.com/problemset/problem/20/C)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
 
using namespace std;
 
// Time: O(V + ElogV)
// Space: O(V)
 
#define INF LLONG_MAX
 
typedef long long ll;
typedef tuple<int,int,ll> edge;
typedef pair<int,ll> graph_edge;
typedef pair<ll,int> state;

vector<vector<graph_edge>> G;
vector<int> vis, P;                                         // shortest-path tree
vector<ll> dist;

void dijkstra(int src) {
    auto comp = [&](const state& s1, const state& s2) {
        return s1.first > s2.first;
    };
    priority_queue<state, vector<state>, decltype(comp)> pq(comp);          // min-heap

    dist[src] = 0;
    pq.push({ dist[src], src });

    while (!pq.empty()) {
        auto s = pq.top();
        pq.pop();

        int u = s.second;
        if (vis[u] == 1)
            continue;
        vis[u] = 1;

        for (graph_edge& e : G[u]) {
            int v = e.first; ll w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                P[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }
}

void solve(vector<edge>& edges, int V, int E) {
    G.assign(V+1, vector<graph_edge>());
    vis.assign(V+1, 0);
    dist.assign(V+1, INF);
    P.assign(V+1, -1);

    int u, v; ll w;
    for (edge& e : edges) {
        tie(u, v, w) = e;
        G[u].push_back({ v, w });
        G[v].push_back({ u, w });
    }

    dijkstra(1);

    if (dist[V] == INF) {
        cout << -1 << endl;
        return;
    }

    vector<int> path;
    int curr = V;
    while (curr != -1) {
        path.push_back(curr);
        curr = P[curr];
    }

    reverse(path.begin(), path.end());

    for (int u : path)
        cout << u << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    int u, v; ll w;
    vector<edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }

    solve(edges, V, E);
    
    return 0;
}