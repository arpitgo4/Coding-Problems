// Sasha and His Trip (https://codeforces.com/problemset/problem/1113/A)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O(N * V)
// Space: O(N * V)
 
/**
 * Note: Get the tank full at each stop if we are deciding
 *       to fuel up as the cost of fuel at current stop will be
 *       minimum compared to any of the next coming stops.
 * 
 * TODO: can be optimized to O(N) time using a greedy approach.
 */

vector<vector<int>> dp;

int dfs(int i, int v, int N, int V) {
    if (v < 0 || v > V)
        return INT_MAX;
    if (i == N)
        return 0;
    if (dp[i][v] != -1)
        return dp[i][v];
    
    int a = dfs(i+1, v-1, N, V);

    int re_fuel = min(N-i, V-v);
    int b = (re_fuel * i) + dfs(i+1, v+re_fuel-1, N, V);

    return dp[i][v] = min(a, b);
}

void solve(int N, int V) {
    dp.assign(N+1, vector<int>(V+1, -1));

    int min_cost = dfs(1, 0, N, V);
    cout << min_cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, V;
    cin >> N >> V;
    
    solve(N, V);
    
    return 0;
}