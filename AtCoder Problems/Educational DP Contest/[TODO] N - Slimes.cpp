// Slimes (https://atcoder.jp/contests/dp/tasks/dp_n)
 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <climits>
 
using namespace std;
 
// Time: O()
// Space: O()

/**
 * Which permutation of the slimes result in the minimum
 * possible cost for combining them into one big slime
 * 
 * Or, the order in which we combine slimes.
 */
 
#define INF LLONG_MAX

typedef long long ll;

const int MAX_N = 400 + 1;

unordered_map<bitset<MAX_N>,ll> dp;

ll dfs(bitset<MAX_N>& mask, vector<ll>& A, int N) {
    if (mask.count() == N)
        return 0;
    if (dp.find(mask) != dp.end())
        return dp[mask];

    ll min_cost = INF;
    for (int i = 0; i < N-1; i++) {
        if (mask[i] == 0) {
            mask.set(i).set(i+1);
            int a = A[i], b = A[i+1];
            A[i] = A[i+1] = a + b

            ll cost = A[i] + dfs(mask, A, N);

            A[i] = a;
            A[i+1] = b;
            mask.reset(i).reset(i+1);

            min_cost = min(min_cost, cost);
        }
    }

    return dp[mask] = min_cost;
}

void solve(vector<ll>& A, int N) {
    bitset<MAX_N> mask(0);
    ll min_cost = dfs(mask, A, N);

    cout << min_cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}