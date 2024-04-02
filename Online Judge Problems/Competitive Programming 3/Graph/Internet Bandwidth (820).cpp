// Internet Bandwidth (820)
 
#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
#include <queue>
#include <cmath>
 
using namespace std;
 
// Time: O(V * E^2)
// Space: O(E)

#define INF INT_MAX
 
typedef long long ll;
typedef tuple<int,int,int> edge;
typedef pair<int,int> state;
 
vector<vector<int>> G, C;
vector<int> vis, P;

int bfs(int src, int sink, int V) {
    vis.assign(V+1, 0);
    P.assign(V+1, -1);

    queue<state> q({{ src, INF }});
    vis[src] = 1;

    while (!q.empty()) {
        state p = q.front();
        q.pop();

        int u = p.first, flow = p.second;
        if (u == sink)
            return flow;

        for (int v : G[u]) {
            if (vis[v] == 0 && C[u][v] > 0) {
                vis[v] = 1;
                P[v] = u;
                q.push({ v, min(flow, C[u][v]) });
            }
        }
    }

    return 0;
}

int maximum_flow(int src, int sink, int V) {
    int flow = 0, max_flow = 0;
    while ((flow = bfs(src, sink, V)) > 0) {
        max_flow += flow;

        int curr = sink;
        while (curr != src) {
            int prev = P[curr];
            C[prev][curr] -= flow;
            C[curr][prev] += flow;
            curr = prev;
        }
    }

    return max_flow;
}

int solve(vector<edge>& edges, int src, int sink, int V, int E) {
    G.assign(V+1, vector<int>());
    C.assign(V+1, vector<int>(V+1, 0));

    int u, v, w;
    for (edge& e : edges) {
        tie (u, v, w) = e;
        G[u].push_back(v);
        G[v].push_back(u);
        C[u][v] += w;
        C[v][u] += w;
    }

    int max_flow = maximum_flow(src, sink, V);
    return max_flow;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int idx = 1, V;
    cin >> V;

    while (V != 0) {
        int src, sink, E;
        cin >> src >> sink >> E;

        int u, v, w;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            edges[i] = { u, v, w };
        }

        int max_bandwidth = solve(edges, src, sink, V, E);
        cout << "Network " << (idx++) << endl;
        cout << "The bandwidth is " << max_bandwidth << "." << endl << endl;

        cin >> V;
    }
    
    return 0;
}