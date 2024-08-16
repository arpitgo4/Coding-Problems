// Longest Path (https://atcoder.jp/contests/dp/tasks)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(V + E)
// Space: O(V + E)
 
typedef pair<int,int> edge;

vector<vector<int>> G;
vector<int> dp;

int dfs(int u) {
    if (dp[u] != -1)
        return dp[u];

    int longest_path = 0;
    for (int v : G[u]) {
        int path = 1 + dfs(v);
        longest_path = max(longest_path, path);
    }

    return dp[u] = longest_path;
}

void solve(vector<edge>& edges, int E, int V) {
    G.assign(V+1, vector<int>());
    dp.assign(V+1, -1);
    for (auto& [u, v] : edges)
        G[u].push_back(v);

    int longest_path = 0;
    for (int u = 1; u <= V; u++)
        longest_path = max(longest_path, dfs(u));

    cout << longest_path << endl;
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