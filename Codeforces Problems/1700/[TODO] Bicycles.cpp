// Bicycles (https://codeforces.com/problemset/problem/1915/G)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
 
using namespace std;
 
// Time: O(V + ElogV)
// Space: O(V)
 
#define INF LLONG_MAX
 
typedef long long ll;
typedef tuple<int,int,ll> edge;
typedef pair<int,ll> graph_edge;
typedef pair<ll,int> state;

vector<vector<graph_edge>> G;
vector<int> vis;
vector<ll> dist;

void dijkstra(int src, vector<int>& s_factor) {
    auto comp = [&](const state& s1, const state& s2) {
        return s1.first > s2.first;
    };
    priority_queue<state, vector<state>, decltype(comp)> pq(comp);              // min-heap

    dist[src] = 0;
    pq.push({ dist[src], src });

    while (!pq.empty()) {
        state s = pq.top();
        pq.pop();

        int u = s.second;
        if (vis[u] == 1)
            continue;
        vis[u] = 1;

        for (graph_edge& e : G[u]) {
            int v = e.first; ll w = e.second;
            ll time = w * s_factor[u];
            if (dist[v] > dist[u] + time) {
                dist[v] = dist[u] + time;
                pq.push({ dist[v], v });
            }
        }
    }
}

void solve(vector<edge>& edges, vector<int>& s_factor, int V, int E) {
    G.assign(V+1, vector<graph_edge>());
    vis.assign(V+1, 0);
    dist.assign(V+1, INF);

    int u, v; ll w;
    for (edge& e : edges) {
        tie(u, v, w) = e;
        G[u].push_back({ v, w });
        G[v].push_back({ u, w });
    }

    dijkstra(1, s_factor);

    cout << dist[V] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        int u, v; ll w;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            edges[i] = { u, v, w };
        }

        int s;
        vector<int> s_factor(V+1);
        for (int i = 1; i <= V; i++) {
            cin >> s;
            s_factor[i] = s;
        }

        solve(edges, s_factor, V, E);
    }

    return 0;
}