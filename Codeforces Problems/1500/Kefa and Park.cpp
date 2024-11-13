// Kefa and Park (https://codeforces.com/problemset/problem/580/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
typedef pair<int,int> edge;

vector<vector<int>> T;

int dfs(int u, int p, int cat_cnt, vector<int>& A, int M) {
    if (cat_cnt > M)
        return 0;
    if (T[u].size() == 1 && u != 1)                                       // leaf vertex
        return 1;

    int cnt = 0;
    for (int v : T[u]) {
        if (v != p) {
            cnt += dfs(v, u, A[v] == 0 ? 0 : cat_cnt + 1, A, M);
        }
    }

    return cnt;
}

void solve(vector<edge>& edges, vector<int>& A, int N, int M) {
    T.assign(N+1, vector<int>());
    for (auto& [u, v] : edges) {
        T[u].push_back(v);
        T[v].push_back(u);
    }

    int count = dfs(1, 1, A[1], A, M);
    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    int u, v;
    vector<edge> edges(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> u >> v;
        edges[i] = { u, v };
    }

    solve(edges, A, N, M);
    
    return 0;
}