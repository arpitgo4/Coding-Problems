// Petr and a Combination Lock (https://codeforces.com/problemset/problem/1097/B)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;

// Time: O(N * 360) ~ O(N)
// Space: O(N * 360) ~ O(N)
 
vector<vector<int>> dp;

int dfs(int i, int curr_pos, vector<int>& degree, int N) {
    if (i == N)
        return curr_pos == 0 ? 1 : 0;
    if (dp[i][curr_pos] != -1)
        return dp[i][curr_pos];
    
    // clockwise rotation
    int a = dfs(i+1, (curr_pos + degree[i]) % 360, degree, N);

    // counter-clockwise rotation
    int new_pos = curr_pos - degree[i];
    if (new_pos < 0)
        new_pos = (360 - (curr_pos - degree[i])) % 360;

    int b = dfs(i+1, new_pos, degree, N);

    return dp[i][curr_pos] = (a == 1 || b == 1 ? 1 : 0);
}

void solve(vector<int>& degree, int N) {
    dp.assign(N, vector<int>(360, -1));
    int can_unlock = dfs(0, 0, degree, N);

    cout << (can_unlock == 1 ? "YES" : "NO");
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> degree(N);
    for (int i = 0; i < N; i++)
        cin >> degree[i];

    solve(degree, N);
    
    return 0;
}