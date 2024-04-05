// Gift Carpet (https://codeforces.com/problemset/problem/1862/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * M * 4) ~ O(N * M)
// Space: O(N * M * 4) ~ O(N * M)
 
vector<vector<char>> A;
vector<vector<int>> dp;

const string name = "vika";
const int L = 4;

int dfs(int j, int c_idx, int N, int M) {
    if (c_idx == L)
        return 1;
    if (j == M)
        return 0;
    if (dp[j][c_idx] != -1)
        return dp[j][c_idx];
    
    int found = 0;
    for (int i = 0; i < N; i++) {
        if (A[i][j] == name[c_idx])
            found |= dfs(j+1, c_idx+1, N, M);
    }

    // if not found in current column, proceed to next column
    // columns need not to be adjacent
    if (found == 0)
        found |= dfs(j+1, c_idx, N, M);

    return dp[j][c_idx] = found;
}

bool solve(int N, int M) {
    dp.assign(M, vector<int>(L, -1));

    int possible = dfs(0, 0, N, M);
    return possible == 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        A.assign(N, vector<char>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> A[i][j];

        bool possible = solve(N, M);
        cout << (possible ? "YES" : "NO") << endl;
    }   
    
    return 0;
}