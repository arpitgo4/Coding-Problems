// Knapsack 1 (https://atcoder.jp/contests/dp/tasks/dp_d)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O(N * K)
// Space: O(N * K)
 
#define NEG_INF INT_MIN

typedef long long ll;

vector<vector<ll>> dp;

ll dfs(int i, int w, vector<ll>& A, vector<int>& W, int N, int K) {
    if (w > K)
        return NEG_INF;
    if (w == K || i == N)
        return 0;
    if (dp[i][w] != -1)
        return dp[i][w];

    ll cost_1 = dfs(i+1, w+W[i], A, W, N, K);
    if (cost_1 != NEG_INF)
        cost_1 += A[i];

    ll cost_2 = dfs(i+1, w, A, W, N, K);

    return dp[i][w] = max(cost_1, cost_2);
}

void solve(vector<ll>& A, vector<int>& W, int N, int K) {
    dp.assign(N+1, vector<ll>(K+1, -1));

    ll max_cost = dfs(0, 0, A, W, N, K);
    cout << max_cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> W(N);
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> W[i] >> A[i];

    solve(A, W, N, K);
    
    return 0;
}