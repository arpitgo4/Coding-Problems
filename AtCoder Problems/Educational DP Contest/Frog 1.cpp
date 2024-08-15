// Frog 1 (https://atcoder.jp/contests/dp/tasks/dp_a)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
#define INF INT_MAX

vector<int> dp;

int dfs(int i, vector<int>& A, int N) {
    if (i == N-1)
        return 0;
    if (i >= N)
        return INF;
    if (dp[i] != -1)
        return dp[i];

    int cost_1 = dfs(i+1, A, N);
    if (cost_1 != INF && i+1 < N)
        cost_1 += abs(A[i+1] - A[i]);

    int cost_2 = dfs(i+2, A, N);
    if (cost_2 != INF && i+2 < N)
        cost_2 += abs(A[i+2] - A[i]);

    return dp[i] = min(cost_1, cost_2);
}

void solve(vector<int>& A, int N) {
    dp.assign(N+1, -1);

    int min_cost = dfs(0, A, N);
    cout << min_cost << endl;
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