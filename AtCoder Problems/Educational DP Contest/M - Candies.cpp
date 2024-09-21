// M - Candies (https://atcoder.jp/contests/dp/tasks/dp_m)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * K^2)
// Space: O(N * K)
 
const int MOD = 1e9 + 7;

vector<vector<int>> dp;

int dfs(int i, int k, vector<int>& A, int N) {
    if (k == 0) 
        return 1;
    if (i == N || k < 0)
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];

    int count = 0;
    for (int j = 0; j <= A[i]; j++)
        count = (count + dfs(i+1, k-j, A, N)) % MOD;

    return dp[i][k] = count;
}

void solve(vector<int>& A, int N, int K) {
    dp.assign(N+1, vector<int>(K+1, -1));

    int count = dfs(0, K, A, N);
    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, K);
    
    return 0;
}