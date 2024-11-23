// Cut Ribbon (https://codeforces.com/problemset/problem/189/A)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
#define NEG_INF INT_MIN

vector<int> dp;

int dfs(int N, int a, int b, int c) {
    if (N < 0)
        return NEG_INF;
    if (N == 0)
        return 0;
    if (dp[N] != -1)
        return dp[N];

    int a_cnt = 1 + dfs(N-a, a, b, c);
    int b_cnt = 1 + dfs(N-b, a, b, c);
    int c_cnt = 1 + dfs(N-c, a, b, c);

    return dp[N] = max(a_cnt, max(b_cnt, c_cnt));
}

void solve(int a, int b, int c, int N) {
    dp.assign(N+1, -1);

    int max_count = dfs(N, a, b, c);
    cout << max_count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, a, b, c;
    cin >> N >> a >> b >> c;

    solve(a, b, c, N);
    
    return 0;
}