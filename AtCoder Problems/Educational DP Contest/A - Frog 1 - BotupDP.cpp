// A - Frog 1 - BotupDP (https://atcoder.jp/contests/dp/tasks/dp_a)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

/**
 * Possible transitions to (i+1) or (i+2)
 * dp[i]: represents min cost of reaching at ith stone
 */
 
#define INF INT_MAX

vector<int> dp;

void solve(vector<int>& A, int N) {
    dp.assign(N+1, 0);

    dp[N-1] = 0;
    for (int i = N-1; i >= 0; i--) {
        int a = INF;
        if (i-1 >= 0)
            a = abs(A[i]-A[i-1]) + dp[i-1];
        int b = INF;
        if (i-2 >= 0)
            b = abs(A[i]-A[i-2]) + dp[i-2];

        dp[i] += min(dp[i], min(a, b));
    }

    cout << dp[0] << endl;
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