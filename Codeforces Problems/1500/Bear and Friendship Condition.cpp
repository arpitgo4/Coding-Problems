// Bear and Friendship Condition (https://codeforces.com/problemset/problem/771/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
/**
 * Among x, y & z
 * 
 * if x & y are connected, i.e. root(x) == root(y)
 * then, x and z should also be connected, i.e. root(x) == root(z)
 * 
 * 
 * For every three distinct members,
 * x - y
 * y - z
 * 
 * then, x - z
 * 
 * looks like a cycle of size 3
 * 
 * Each connected component should be a Clique,
 * i.e. a subgraph in which every pair of vertices
 * are adjacent to each other i.e. connected to each
 * other by an edge.
 * 
 * #edge in clique = (#vertices * (#vertices - 1)) / 2
 */

typedef long long ll;
typedef pair<int,int> edge;

vector<vector<int>> G;
vector<int> vis;

void dfs(int u, ll& v_cnt, ll& e_cnt) {
    vis[u] = 1;
    for (int v : G[u]) {
        e_cnt += 1;

        if (vis[v] == 0) {
            v_cnt += 1;
            dfs(v, v_cnt, e_cnt);
        }
    }

    vis[u] = 2;
}

void solve(vector<edge>& edges, int E, int V) {
    G.assign(V+1, vector<int>());
    vis.assign(V+1, 0);
    for (auto& [u, v] : edges) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for (int u = 1; u <= V; u++) {
        if (vis[u] == 0) {
            ll v_cnt = 1, e_cnt = 0;
            dfs(u, v_cnt, e_cnt);

            if (e_cnt != (v_cnt * (v_cnt-1))) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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