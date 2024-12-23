// terraces (https://open.kattis.com/problems/terraces)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)
 
vector<vector<int>> vis;
vector<int> P, S, out;

vector<pair<int,int>> moves{
    { -1, 0 },              // up
    { 1, 0 },               // down
    { 0, -1 },              // left
    { 0, 1 }                // right
};

void init_dsu(int N) {
    P.assign(N+1, -1);
    S.assign(N+1, 1);
    for (int i = 0; i <= N; i++)
        P[i] = i;
}

int root(int x) {
    if (P[x] != x)
        P[x] = root(P[x]);

    return P[x];
}

void union_set(int x, int y) {
    int root_x = root(x);
    int root_y = root(y);
    if (root_x != root_y) {
        if (S[root_x] < S[root_y])
            swap(root_x, root_y);

        P[root_y] = root_x;
        S[root_x] += S[root_y];
    }
}

int get_idx(int i, int j, int M) {
    return M * i + j;
}

void dfs(int i, int j, vector<vector<int>>& A, int N, int M) {
    if (i < 0 || i == N || j < 0 || j == M || vis[i][j] != 0)
        return;

    vis[i][j] = 1;

    int root_x = root(get_idx(i, j, M));
    for (auto& [di, dj] : moves) {
        int n_i = i + di, n_j = j + dj;
        if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M && A[n_i][n_j] <= A[i][j]) {
            if (root_x != root(get_idx(n_i, n_j, M)))
                out[root_x]++;

            dfs(n_i, n_j, A, N, M);
        }
    }

    vis[i][j] = 2;
}

void solve(vector<vector<int>>& A, int N, int M) {
    init_dsu(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i-1 >= 0 && A[i-1][j] == A[i][j]) {
                union_set(get_idx(i-1, j, M), get_idx(i, j, M));
            }
            if (j-1 >= 0 && A[i][j-1] == A[i][j]) {
                union_set(get_idx(i, j-1, M), get_idx(i, j, M));
            }
        }
    }

    vis.assign(N+1, vector<int>(M+1, 0));
    out.assign(N * M, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j] == 0) {
                dfs(i, j, A, N, M);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int idx = get_idx(i, j, M);
            int root_x = root(idx);
            if (idx == root_x && out[root_x] == 0)
                count += S[root_x];
        }
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> M >> N;

    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    solve(A, N, M);
    
    return 0;
}