// Frog 2 (https://atcoder.jp/contests/dp/tasks/dp_b)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;
 
// Time: O(N * K)
// Space: O(N)
 
#define INF INT_MAX

vector<int> dp;

int dfs(int i, vector<int>& A, int N, int K) {
    if (i == N-1)
        return 0;
    if (i >= N)
        return INF;
    if (dp[i] != -1)
        return dp[i];

    int min_cost = INF;
    for (int j = 1; j <= K; j++) {
        int cost = dfs(i+j, A, N, K);

        if (cost != INF && i+j < N) 
            min_cost = min(min_cost, cost + abs(A[i+j] - A[i]));
    }

    return dp[i] = min_cost;
}

void solve(vector<int>& A, int N, int K) {
    dp.assign(N+1, -1);

    int min_cost = dfs(0, A, N, K);
    cout << min_cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K; 
    
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, K);
    
    return 0;
}