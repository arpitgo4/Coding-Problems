// Kuroni and Impossible Calculation (https://codeforces.com/problemset/problem/1305/C)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
using ll = long long;

// Time: O(N^2)
// Space: O(1)

// Let's consider 2 cases.
// 1. 𝑛≤𝑚. Then we can calculate this product directly in 𝑂(𝑛^2).
// 2. 𝑛>𝑚. Note that there are only 𝑚 possible remainders under division by 𝑚, so some 2 numbers of 𝑛 have the same remainder. Then their difference is divisible by 𝑚, so the entire product is 0 mod 𝑚.

ll naive_solution(vector<ll>& A, ll N, ll MOD) { 
    ll res = 1; 
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            res = (res * abs(A[i] - A[j])) % MOD;

    return res;
}

void solve(vector<ll>& A, ll N, ll MOD) {
    if (N > MOD) {
        cout << 0;
        return;
    }

    ll res = naive_solution(A, N, MOD);

    cout << res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, MOD;
    cin >> N >> MOD;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N, MOD);
    
    return 0;
}