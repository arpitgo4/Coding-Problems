// Long Jumps (https://codeforces.com/problemset/problem/1472/C)
 
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
 
using namespace std;
 
#define NEG_INF LLONG_MIN;

typedef long long ll;
 
// Time: O(N)
// Space: O(N)

vector<ll> dp;

ll dfs(int i, vector<ll>& A, int N) {
    if (i >= N)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    
    return dp[i] = A[i] + dfs(i+A[i], A, N);
}

void solve(vector<ll>& A, int N) {
    dp.assign(N, -1);

    ll max_score = NEG_INF;
    for (int i = 0; i < N; i++)
        max_score = max(max_score, dfs(i, A, N));

    cout << max_score << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<ll> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }   
    
    return 0;
}