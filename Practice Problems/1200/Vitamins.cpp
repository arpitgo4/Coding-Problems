// Vitamins (https://codeforces.com/problemset/problem/1042/B)
 
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
 
using namespace std;
 
// Time: O(N * 7) ~ O(N)
// Space: O(N * 8) ~ O(N)
 
vector<vector<int>> dp;

int dfs(int i, int mask, vector<int>& prices, vector<int>& vitamins, int N) {
    if (mask == 7)                          // all vitamins acquired
        return 0;
    if (i == N)                             // not able to acquire all vitamins
        return INT_MAX;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    
    int a = dfs(i+1, mask | vitamins[i], prices, vitamins, N);
    if (a != INT_MAX)
        a += prices[i];

    int b = dfs(i+1, mask, prices, vitamins, N);

    return dp[i][mask] = min(a, b);
}

void solve(vector<int>& prices, vector<int>& vitamins, int N) {
    dp.assign(N, vector<int>(7+1, -1));

    int min_price = dfs(0, 0, prices, vitamins, N);
    cout << (min_price == INT_MAX ? -1 : min_price);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    string v_str;
    vector<int> prices(N), vitamins(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> prices[i] >> v_str;
        for (char c : v_str)
            vitamins[i] ^= (1 << (c - 'A'));
    }

    solve(prices, vitamins, N);
    
    return 0;
}