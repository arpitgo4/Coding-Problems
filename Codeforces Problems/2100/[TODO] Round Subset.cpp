// Round Subset (https://codeforces.com/contest/837/problem/D)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O()
// Space: O()

/**
 * Knapsack DP (3D DP problem)
 * 
 * count number of primes (2, 5) this will only
 * turn into a zero.
 * 
 * TODO: We will need one more layer of dimension that is
 * count of factors...
 */

typedef long long ll;
 
vector<vector<pair<int,int>>> dp;
vector<pair<int,int>> factors;

void factorize(vector<ll>& A, int N) {
    factors.assign(N, { 0, 0 });

    for (int i = 0; i < N; i++) {
        while (A[i] % 2 == 0) {
            A[i] /= 2;
            factors[i].first++;
        }

        while (A[i] % 5 == 0) {
            A[i] /= 5;
            factors[i].second++;
        }
    }
}

pair<int,int> dfs(int i, int K, int N) {
    if (K == 0)
        return { 0, 0 };
    if (i == N)
        return { INT_MIN, INT_MIN };
    if (dp[i][K].first != -1)
        return dp[i][K];
    
    pair<int,int> a = dfs(i+1, K-1, N);
    int max_1 = min(a.first + factors[i].first, a.second + factors[i].second);

    pair<int,int> b = dfs(i+1, K, N);
    int max_2 = min(b.first, b.second);

    if (max_1 > max_2)
        dp[i][k] = { a.first + factors[i].first, a.second + factors[i].second };
    else dp[i][k] = b;


}

void solve(vector<ll>& A, int N, int K) {
    dp.assign(N, vector<pair<int,int>>(K+1, { -1, -1 }));
    factorize(A, N);
    
    pair<int,int> max_pair = dfs(0, K, N);
    int max_zero = min(max_pair.first, max_pair.second);
    cout << max_zero << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, K);
    
    return 0;
}