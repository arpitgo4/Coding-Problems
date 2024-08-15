// Vacation (https://atcoder.jp/contests/dp/tasks/dp_c)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * 3) ~ O(N)
// Space: O(N * 3) ~ O(N)
 
vector<vector<int>> dp;

int dfs(int i, int prev, vector<vector<int>>& A, int N) {
    if (i == N)
        return 0;
    if (dp[i][prev] != -1)
        return dp[i][prev];

    int max_val = 0;
    for (int j = 0; j < 3; j++) {
        if (j != prev)
            max_val = max(max_val, A[i][j] + dfs(i+1, j, A, N));
    }

    return dp[i][prev] = max_val;
}

void solve(vector<vector<int>>& A, int N) {
    dp.assign(N+1, vector<int>(3, -1));

    int max_val = 0;
    for (int j = 0; j < 3; j++)
        max_val = max(max_val, dfs(0, j, A, N));

    cout << max_val << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<vector<int>> A(N, vector<int>(3));
    for (int i = 0; i < N; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    solve(A, N);
    
    return 0;
}