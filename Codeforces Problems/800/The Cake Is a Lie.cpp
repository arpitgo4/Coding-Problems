// The Cake Is a Lie (https://codeforces.com/problemset/problem/1519/B)
 
#include <iostream>
#include <vector>
#include <bitset>
 
using namespace std;
 
// Time: O(N * M * K)
// Space: O(N * M * K)

// 1e8 ~ 100 * 1e6 MB (this is in bytes)
// 4 * 100MB = 400 MB (due to using integer) (memory limit is 256MB)

#define bit bitset<1>

vector<vector<vector<bit>>> dp;

bit dfs(int i, int j, int k, int N, int M) {
    if (i < 0 || i == N || j < 0 || j == M || k < 0)
        return 0;
    if (i == N-1 && j == M-1)
        return k == 0 ? 1 : 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    bit c1 = dfs(i+1, j, k-(j+1), N, M);
    bit c2 = dfs(i, j+1, k-(i+1), N, M);

    return dp[i][j][k] = c1 | c2;
}

bool solve(int N, int M, int K) {
    dp.assign(N, vector<vector<bit>>(M, vector<bit>(K+1, -1)));

    bit possible = dfs(0, 0, K, N, M);
    return possible.count() == 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        bool possible = solve(N, M, K);
        cout << (possible ? "YES" : "NO") << endl;
    }
    
    return 0;
}