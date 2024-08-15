// Knapsack 2 (https://atcoder.jp/contests/dp/tasks/dp_e)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O()
// Space: O()
 
#define NEG_INF INT_MIN

typedef long long ll;

vector<vector<ll>> dp;

void solve(vector<ll>& A, vector<ll>& W, int N, ll K) {
    dp.assign(N+1, vector<ll>(K+1, -1));

    ll max_val = dfs(0, 0, A, W, N, K);
    cout << max_val << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    ll K;
    cin >> N >> K;
    
    vector<ll> A(N);
    vector<ll> W(N);
    for (int i = 0; i < N; i++)
        cin >> W[i] >> A[i];

    solve(A, W, N, K);
    
    return 0;
}