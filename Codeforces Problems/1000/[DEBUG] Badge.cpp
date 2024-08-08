// Badge (https://codeforces.com/problemset/problem/1020/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

/**
 * FAILING FOR 1 TEST CASE!!!
 * 
 * Refer this: https://cses.fi/paste/a7027f6882a3d6af144d1a/
 * 
 * Observations about the problem,
 * 1. As there are N edges, there has to be a cycle. 
 *    Simplest graph without a cycle has N-1 edges 
 *    which is a tree.
 * 
 * For nodes in cycle, output for them is themselves,
 * for nodes outside the cycle, first node in the cycle
 * is the output for them.
 * 
 * See the problem as identifying all nodes within the cycle
 * 
 * Once I enter the cycle, I can't get out of it
 * this way all nodes within the cycle can be found out
 */

vector<int> vis1, vis2, dp;

// finds cycle node
int dfs(int u, vector<int>& P) {
    if (vis1[u] == 1)
        return u;

    vis1[u] = 1;

    int v = P[u];
    return dfs(v, P);
}

int dfs2(int u, vector<int>& P) {
    if (dp[u] != -1)
        return dp[u];

    int v = P[u];
    return dp[u] = dfs2(v, P);
}

void solve(vector<int>& P, int N) {
    dp.assign(N+1, -1);
    vis1.assign(N+1, 0);
    vis2.assign(N+1, 0);

    for (int i = 1; i <= N; i++) {
        if (vis1[i] == 0) {
            int curr = dfs(i, P);

            while (vis2[curr] == 0) {
                vis2[curr] = 1;
                dp[curr] = curr;
                curr = P[curr];
            }
        }
    }

    for (int i = 1; i <= N; i++)
        dfs2(i, P);

    for (int i = 1; i <= N; i++)
        cout << dp[i] << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> P(N+1);
    for (int i = 1; i <= N; i++)
        cin >> P[i];

    solve(P, N);
    
    return 0;
}