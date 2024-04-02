// Stone Game (https://codeforces.com/problemset/problem/1538/A)
 
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
 
using namespace std;
 
// Time: O(N^2)
// Space: O(N^2)
 
vector<vector<int>> dp;

int dfs(int l, int h, int max_idx, int min_idx, int N) {
    if (l > h)
        return 0;
    if ((max_idx < l || max_idx > h) && (min_idx < l || min_idx > h))
        return 0;
    if (dp[l][h] != -1)
        return dp[l][h];

    int a = 1 + dfs(l+1, h, max_idx, min_idx, N);
    int b = 1 + dfs(l, h-1, max_idx, min_idx, N);

    return dp[l][h] = min(a, b);
}

void solve(vector<int>& A, int N) {
    dp.assign(N, vector<int>(N, -1));
    
    int max_idx = -1, min_idx = -1;
    int max_e = INT_MIN, min_e = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (A[i] > max_e) {
            max_e = A[i];
            max_idx = i;    
        }
        if (A[i] < min_e) {
            min_e = A[i];
            min_idx = i;
        }
    }

    int min_moves = dfs(0, N-1, max_idx, min_idx, N);
    cout << min_moves << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    vector<int> out;
    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }
    
    return 0;
}