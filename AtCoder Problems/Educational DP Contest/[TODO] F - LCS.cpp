// LCS (https://atcoder.jp/contests/dp/tasks/dp_f)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)
 
vector<vector<int>> dp, P;

int dfs(int i, int j, string& S, int N, string& T, int M) {
    if (i == N || j == M)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int len = (S[i] == T[j] ? 1 : 0);
    int a = len + dfs(i+1, j+1, S, N, T, M);

    int b = dfs(i+1, j, S, N, T, M);
    int c = dfs(i, j+1, S, N, T, M);

    return dp[i][j] = max({ a, b, c });
}

void solve(string& S, string& T) {
    int N = S.length();
    int M = T.length();

    dp.assign(N, vector<int>(M, -1));
    P.assign(N, vector<int>(M, -1));

    int len = dfs(0, 0, S, N, T, M);
    cout << len << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S, T;
    cin >> S >> T;
    
    solve(S, T);
    
    return 0;
}