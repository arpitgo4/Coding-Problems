// Sending email (10986)
 
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>
 
using namespace std;
 
// Time: O(V + ElogV)
// Space: O(V)
 
#define INF LLONG_MAX
 
typedef long long ll;
typedef tuple<int,int,ll> edge;
typedef pair<int,ll> graph_edge;
typedef pair<ll,int> state;
 
vector<vector<graph_edge>> G;
vector<ll> dist;
vector<int> vis;

void dijkstra(int src, int dest) {
    auto comp = [&](const state& s1, const state& s2) {
        return s1.first > s2.first;
    };
    priority_queue<state, vector<state>, decltype(comp)> q(comp);           // min-heap

    dist[src] = 0;
    q.push({ dist[src], src });

    while (!q.empty()) {
        auto p = q.top();
        q.pop();

        int u = p.second;
        if (vis[u] != 0)
            continue;
        vis[u] = 1;

        for (graph_edge& e : G[u]) {
            int v = e.first; ll w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({ dist[v], v });
            }
        }
    }
}

ll solve(vector<edge>& edges, int V, int E, int src, int dest) {
    G.assign(V+1, vector<graph_edge>());
    dist.assign(V+1, INF);
    vis.assign(V+1, 0);

    int u, v; ll w;
    for (edge& e : edges) {
        tie (u, v, w) = e;
        G[u].push_back({ v, w });
        G[v].push_back({ u, w });
    }

    dijkstra(src, dest);

    return dist[dest];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int V, E, src, dest;
        cin >> V >> E >> src >> dest;

        int u, v; ll w;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            edges[i] = { u, v, w };
        }

        ll time = solve(edges, V, E, src, dest);
        cout << "Case #" << t << ": ";
        if (time == INF)
            cout << "unreachable" << endl;
        else cout << time << endl;
    }
    
    return 0;
}