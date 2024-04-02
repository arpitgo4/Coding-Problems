// Come and Go (11838)
 
#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
#include <stack>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)

typedef tuple<int,int,int> edge;
 
vector<vector<int>> G;
vector<int> s_time, low_link, vis;
vector<bool> on_stack;
stack<int> st;

int scc_count, timer;

void dfs(int u) {
    s_time[u] = timer++;
    low_link[u] = s_time[u];
    st.push(u);
    on_stack[u] = true;
    vis[u] = 1;

    for (int v : G[u]) {
        if (vis[v] == 0) {
            dfs(v);
            low_link[u] = min(low_link[u], low_link[v]);
        } else if (on_stack[v])
            low_link[u] = min(low_link[u], s_time[v]);
    }

    if (s_time[u] == low_link[u]) {
        scc_count++;
        int v;
        do {
            v = st.top();
            st.pop();
            on_stack[v] = false;
        } while (v != u);
    }
}

void solve(vector<edge>& edges, int V, int E) {
    G.assign(V+1, vector<int>());
    vis.assign(V+1, 0);
    s_time.assign(V+1, -1);
    low_link.assign(V+1, -1);
    on_stack.assign(V+1, false);
    timer = 0;
    scc_count = 0;

    int u, v, p;
    for (edge& e : edges) {
        tie (u, v, p) = e;
        G[u].push_back(v);
        if (p == 2)
            G[v].push_back(u);
    }

    for (int u = 1; u <= V; u++)
        if (vis[u] == 0)
            dfs(u);

    cout << (scc_count == 1 ? 1 : 0) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    while (V > 0 && E > 0) {

        int u, v, p;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> p;
            edges[i] = { u, v, p };
        }

        solve(edges, V, E);

        cin >> V >> E;
    }
    
    return 0;
}