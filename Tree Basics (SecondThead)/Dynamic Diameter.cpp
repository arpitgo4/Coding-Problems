// Dynamic Diameter (https://codeforces.com/gym/102694/problem/B)

#include <iostream>
#include <vector>
 
using namespace std;

// Time: O(N)
// Space: O(N)

vector<vector<int>> T;
vector<int> dp_down, dp_up, max_1, max_2, max_1_node;
int diameter = 0;

void re_root(int u, int p) {
    if (p != -1) {
        dp_up[u] = 1 + dp_up[p];
        if (max_1_node[p] != u)
            dp_up[u] = max(dp_up[u], 1 + max_1[p]);
        else dp_up[u] = max(dp_up[u], 1 + max_2[p]);
    }

    for (int v : T[u])
        if (v != p)
            re_root(v, u);

    diameter = max(diameter, dp_down[u] + dp_up[u]);
}

int dfs(int u, int p) {
    for (int v : T[u]) {
        if (v != p) {
            int dist = 1 + dfs(v, u);
            if (dist > max_1[u]) {
                max_2[u] = max_1[u];
                max_1[u] = dist;
                max_1_node[u] = v;
            } else if (dist > max_2[u])
                max_2[u] = dist;
        }
    }

    return dp_down[u] = max_1[u];
}

void solve(vector<pair<int,int>>& edges, int N) {
    T.assign(N+1, vector<int>());
    dp_down.assign(N+1, 0);
    dp_up.assign(N+1, 0);
    max_1.assign(N+1, 0);
    max_2.assign(N+1, 0);
    max_1_node.assign(N+1, -1);
    for (pair<int,int>& e : edges) {
        int u = e.first, v = e.second;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    dfs(1, -1);
    re_root(1, -1);

    for (int u = 1; u < N+1; u++)
        cout << (max(diameter, 1 + max(dp_down[u], dp_up[u]))) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int u, v;
    vector<pair<int,int>> edges(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> u >> v;
        edges[i] = { u, v };
    }

    solve(edges, N);
    
    return 0;
}