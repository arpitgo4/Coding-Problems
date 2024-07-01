// Metro (https://codeforces.com/problemset/problem/1055/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
vector<vector<int>> G;
vector<int> vis;

void dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) {
        if (v == -1)
            continue;
        if (vis[v] == 0)
            dfs(v);
    }
    vis[u] = 2;
}

void solve(vector<int>& right, vector<int>& left, int N, int S) {
    G.assign(N+1, vector<int>());
    vis.assign(N+1, 0);

    int closest_station = -1;
    for (int i = N-1; i >= 0; i--) {
        if (right[i] == 1) {
            G[i].push_back(closest_station);
            closest_station = i;
        }
    }

    closest_station = -1;
    for (int i = 0; i < N; i++) {
        if (left[i] == 1) {
            G[i].push_back(closest_station);
            closest_station = i;
        }
    }

    dfs(0);

    cout << (vis[S-1] ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, S;
    cin >> N >> S;

    vector<int> right(N);
    for (int i = 0; i < N; i++)
        cin >> right[i];
    
    vector<int> left(N);
    for (int i = 0; i < N; i++)
        cin >> left[i];

    solve(right, left, N, S);
    
    return 0;
}