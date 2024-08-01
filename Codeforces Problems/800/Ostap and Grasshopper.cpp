// Ostap and Grasshopper (https://codeforces.com/problemset/problem/735/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
vector<int> vis, dp;

int dfs(int i, string& S, int N, int K) {
    if (i < 0 || i >= N || S[i] == '#' || vis[i] == 1)
        return 0;
    if (S[i] == 'T')
        return 1;
    if (dp[i] != -1)
        return dp[i];
    
    vis[i] = 1;
    return dp[i] = dfs(i+K, S, N, K) | dfs(i-K, S, N, K);
}

void solve(string& S, int N, int K) {
    vis.assign(N, 0);
    dp.assign(N, -1);
    
    int j = -1;
    for (int i = 0; i < N; i++)
        if (S[i] == 'G')
            j = i;

    int can_reach = dfs(j, S, N, K);
    cout << (can_reach == 1 ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    solve(S, N, K);
    
    return 0;
}