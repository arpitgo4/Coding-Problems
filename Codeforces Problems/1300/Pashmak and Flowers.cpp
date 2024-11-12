// Pashmak and Flowers (https://codeforces.com/problemset/problem/459/B)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
typedef long long ll;

void solve(vector<ll>& A, ll N) {
    ll mn = 1e9+1, mx = 0;
    for (int a : A) {
        mn = min<ll>(mn, a);
        mx = max<ll>(mx, a);
    }

    ll mn_cnt = 0, mx_cnt = 0;
    for (int a : A) {
        if (a == mn)
            mn_cnt++;
        else if (a == mx)
            mx_cnt++;
    }

    cout << (mx-mn) << " ";
    if (mn == mx) {
        cout << ((N * (N-1)) / 2) << endl;
    } else {
        cout << (mn_cnt * mx_cnt) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N;
    cin >> N;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}