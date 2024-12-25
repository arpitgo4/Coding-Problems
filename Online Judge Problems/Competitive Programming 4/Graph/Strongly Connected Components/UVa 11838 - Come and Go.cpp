// UVa 11838 - Come and Go (https://onlinejudge.org/external/118/11838.pdf)
 
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <tuple>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
#define INF INT_MAX

typedef tuple<int,int,int> edge;

vector<vector<int>> G;
vector<int> vis, low_link, s_time;

vector<bool> on_stk;
stack<int> stk;

int timer, scc_count;

void dfs(int u) {
    s_time[u] = low_link[u] = timer++;
    stk.push(u);
    on_stk[u] = true;
    vis[u] = 1;

    for (int v : G[u]) {
        if (vis[v] == 0) {                                                  // tree-edge
            dfs(v);
            low_link[u] = min(low_link[u], low_link[v]);
        } else if (on_stk[v]) {                                             // back-edge or bidirectional-edge
            low_link[u] = min(low_link[u], s_time[v]);
        }
    }

    if (s_time[u] == low_link[u]) {
        scc_count += 1;

        int v;
        do {
            v = stk.top();
            stk.pop();
            on_stk[v] = false;
        } while (v != u);
    }

    vis[u] = 2;
}

void solve(vector<edge>& edges, int E, int V) {
    G.assign(V+1, vector<int>());
    vis.assign(V+1, 0);
    s_time.assign(V+1, -1);
    low_link.assign(V+1, INF);
    on_stk.assign(V+1, false);
    timer = 0;
    scc_count = 0;

    int u, v, p;
    for (auto& tup : edges) {
        tie(u, v, p) = tup;
        G[u].push_back(v);
        if (p == 2)
            G[v].push_back(u);
    }
 
    for (int u = 1; u <= V; u++) {
        if (vis[u] == 0)
            dfs(u);
    }

    cout << (scc_count == 1 ? 1 : 0) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    while (V != 0 && E != 0) {
        vector<edge> edges(E);

        int u, v, p;
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> p;
            edges[i] = { u, v, p };
        }

        solve(edges, E, V);

        cin >> V >> E;
    }
    
    return 0;
}