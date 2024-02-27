// The Lakes (https://codeforces.com/problemset/problem/1829/E)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)
 
vector<vector<int>> vis;

int dfs(int i, int j, vector<vector<int>>& A, int N, int M) {
    if (i < 0 || i == N || j < 0 || j == M || A[i][j] == 0)
        return 0;
    if (vis[i][j] != 0)
        return 0;

    vis[i][j] = 1;

    int vol = A[i][j];
    vol += dfs(i-1, j, A, N, M);
    vol += dfs(i+1, j, A, N, M);
    vol += dfs(i, j-1, A, N, M);
    vol += dfs(i, j+1, A, N, M);

    vis[i][j] = 2;

    return vol;
}

void solve(vector<vector<int>>& A, int N, int M) {
    vis.assign(N, vector<int>(M, 0));

    int max_vol = 0;
    for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (vis[i][j] == 0)
                    max_vol = max(max_vol, dfs(i, j, A, N, M));

    cout << max_vol << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> A(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> A[i][j];

        solve(A, N, M);
    }
    
    return 0;
}