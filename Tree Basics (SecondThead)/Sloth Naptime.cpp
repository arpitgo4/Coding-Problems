// Sloth Naptime (https://codeforces.com/gym/102694/problem/C)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(NlogN + QlogN)
// Space: O(NlogN)

vector<vector<int>> T;
vector<vector<int>> sparse_table;
vector<int> depth, parent;

void binary_lift(int N) {
    int max_pow = log2(N) + 1;
    sparse_table.assign(max_pow, vector<int>(N+1, -1));

    for (int u = 1; u <= N; u++)
        sparse_table[0][u] = parent[u];

    for (int pow = 1; pow < max_pow; pow++)
        for (int u = 1; u <= N; u++) {
            int p1 = sparse_table[pow-1][u];
            int p2 = (p1 != -1) ? sparse_table[pow-1][p1] : -1;
            sparse_table[pow][u] = p2;
        }
}

int query_sparse_table(int u, int K) {
    if (u == -1 || K == 0)
        return u;

    int pow = log2(K);
    int p = sparse_table[pow][u];
    return query_sparse_table(p, K - (1 << pow));
}

int query(int u, int v, int energy) {
    int start_node, end_node;
    if (depth[u] > depth[v]) {
        start_node = u;
        end_node = v;     
    } else {
        start_node = v;
        end_node = u;
    }
    
    int K = depth[start_node] - depth[end_node];
    if (energy >= K)
        return end_node;

    return query_sparse_table(start_node, K);
}

void dfs(int u, int p, int dep) {
    depth[u] = dep;
    parent[u] = p;

    for (int v : T[u])
        if (v != p)
            dfs(v, u, dep+1);
}
 
void build_tree(vector<pair<int,int>>& edges, int N) {
    T.assign(N+1, vector<int>());
    depth.assign(N+1, 0);
    parent.assign(N+1, -1);
    for (pair<int,int>& e : edges) {
        int u = e.first, v = e.second;
        T[u].push_back(v);
        T[v].push_back(u);
    }
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

    build_tree(edges, N);
    dfs(1, -1, 0);
    binary_lift(N);

    int Q, energy;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> u >> v >> energy;
        cout << query(u, v, energy) << endl;
    }
    
    return 0;
}