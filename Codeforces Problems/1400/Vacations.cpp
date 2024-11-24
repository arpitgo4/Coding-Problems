// Vacations (https://codeforces.com/problemset/problem/698/A)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(N * 5) ~ O(N)
// Space: O(N * 5) ~ O(N)
 
vector<vector<int>> dp;

int dfs(int i, int p, vector<int>& A, int N) {
    if (i == N)
        return 0;
    if (dp[i][p] != -1)
        return dp[i][p];

    int count = 0;
    if (A[i] == 0)
        count = 1 + dfs(i+1, 0, A, N);
    else if (A[i] == 1) {
        if (p == 1) 
            count = 1 + dfs(i+1, 0, A, N);
        else
            count = dfs(i+1, 1, A, N);
    } else if (A[i] == 2) {
        if (p == 2)
            count = 1 + dfs(i+1, 0, A, N);
        else 
            count = dfs(i+1, 2, A, N);
    } else {                                                        // A[i] == 3
        if (p == 1)
            count = dfs(i+1, 2, A, N);
        else if (p == 2) 
            count = dfs(i+1, 1, A, N);
        else                                                        // p == 0
            count = min(dfs(i+1, 1, A, N), dfs(i+1, 2, A, N));
    }

    return dp[i][p] = count;
}

void solve(vector<int>& A, int N) {
    dp.assign(N+1, vector<int>(5, -1));

    int count = dfs(0, 0, A, N);
    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}