// Grid 1 (https://atcoder.jp/contests/dp/tasks/dp_h)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)
 
typedef long long ll;

const ll MOD = 1e9 + 7;

vector<vector<int>> G;
vector<vector<ll>> dp;

ll dfs(int i, int j, int N, int M) {
    if (i == N || j == M || G[i][j] == 1)
        return 0;
    if (i == N-1 && j == M-1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    ll count = 0;
    count = (count + dfs(i+1, j, N, M)) % MOD;
    count = (count + dfs(i, j+1, N, M)) % MOD;

    return dp[i][j] = count;
}

void solve(int N, int M) {
    ll count = dfs(0, 0, N, M);
    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    G.assign(N, vector<int>(M, 0));
    dp.assign(N, vector<ll>(M, -1));

    char c;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == '#')
                G[i][j] = 1;
        }

    solve(N, M);
    
    return 0;
}