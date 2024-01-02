// Min Path (https://codeforces.com/gym/102644/problem/F)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
 
using namespace std;
using ll = long long;
 
// Time: O(V^3 * logK)
// Space: O(V^2)

vector<vector<ll>> G;

vector<vector<ll>> process_matrix(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    int N = A.size();
    vector<vector<ll>> res(N, vector<ll>(N, LLONG_MAX));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (A[i][k] != LLONG_MAX && B[k][j] != LLONG_MAX)
                    res[i][j] = min(res[i][j], A[i][k] + B[k][j]);

    return res;
}

vector<vector<ll>> matrix_exponentiation(vector<vector<ll>>& mat, ll p) {
    int N = mat.size();
    vector<vector<ll>> res(N, vector<ll>(N, LLONG_MAX));
    for (int i = 0; i < N; i++)
        res[i][i] = 0;

    while (p > 0) {
        if (p % 2 == 1) {
            res = process_matrix(res, mat);
            p--;
        }

        mat = process_matrix(mat, mat);
        p >>= 1;
    }

    return res;
}

void solve(int V, int E, int K, vector<tuple<int,int,ll>>& edges) {
    G.assign(V, vector<ll>(V, LLONG_MAX));
    for (tuple<int,int,ll>& e : edges) {
        int u, v; ll w;
        tie(u,v,w) = e; 
        G[u-1][v-1] = w;
    }

    vector<vector<ll>> G_exp = matrix_exponentiation(G, K);

    ll min_path = LLONG_MAX;
    for (vector<ll>& v : G_exp)
        for (ll a : v)
            min_path = min(min_path, a);

    if (min_path == LLONG_MAX)
        cout << "IMPOSSIBLE";
    else cout << min_path;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E, K;
    cin >> V >> E >> K;

    int u, v; ll w;
    vector<tuple<int,int,ll>> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }

    solve(V, E, K, edges);
    
    return 0;
}