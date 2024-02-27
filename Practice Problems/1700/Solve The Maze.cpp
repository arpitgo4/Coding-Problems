// Solve The Maze (https://codeforces.com/problemset/problem/1365/D)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)
  
vector<vector<int>> vis;

int good_reachable = 0;
bool is_bad_reachable = false;

void dfs(int i, int j, vector<vector<int>>& A, int N, int M) {
    if (i < 0 || i == N || j < 0 || j == M || A[i][j] == 1)
        return;
    if (vis[i][j] != 0)
        return;

    vis[i][j] = 1;

    if (A[i][j] == 2)
        good_reachable++;
    if (A[i][j] == -2)
        is_bad_reachable = true;
    
    dfs(i-1, j, A, N, M);
    dfs(i+1, j, A, N, M);
    dfs(i, j-1, A, N, M);
    dfs(i, j+1, A, N, M);

    vis[i][j] = 2;
}

void place_walls(int i, int j, vector<vector<int>>& A, int N, int M) {
    if (i-1 >= 0 && A[i-1][j] == 0)
        A[i-1][j] = 1;
    if (i+1 < N && A[i+1][j] == 0)
        A[i+1][j] = 1;
    if (j-1 >= 0 && A[i][j-1] == 0)
        A[i][j-1] = 1;
    if (j+1 < M && A[i][j+1] == 0)
        A[i][j+1] = 1;
}

void solve(vector<vector<int>>& A, int N, int M) {
    vis.assign(N, vector<int>(M, 0));

    int good_count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (A[i][j] == -2)
                place_walls(i, j, A, N, M);
            else if (A[i][j] == 2)
                good_count++;
        }

    dfs(N-1, M-1, A, N, M);
    cout << (good_reachable == good_count && !is_bad_reachable ? "Yes" : "No") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        good_reachable = 0;
        is_bad_reachable = false;

        char c;
        vector<vector<int>> A(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                cin >> c;
                if (c == '#') A[i][j] = 1;
                else if (c == 'G') A[i][j] = 2;
                else if (c == 'B') A[i][j] = -2;
            }

        solve(A, N, M);
    }
    
    return 0;
}