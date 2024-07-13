// Can I Square? (https://codeforces.com/problemset/problem/1915/C)
 
#include <iostream>
#include <vector>
 
using namespace std;

typedef long long ll;
 
// Time: O(N + log1e14) ~ O(N)
// Space: O(1)
 
void solve(vector<ll>& A, int N) {
    ll sum = 0;
    for (ll a : A)
        sum += a;

    ll l = 1, h = 1e14;
    while (l <= h) {
        ll m = (h-l)/2 + l;
        if (sum % m == 0 && sum / m == m) {
            cout << "YES" << endl;
            return;
        } else if (sum / m > m)
            l = m+1;
        else h = m-1;
    }

    cout << "NO" << endl;
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