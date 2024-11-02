// Robin Hood in Town (https://codeforces.com/problemset/problem/2014/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN + logN)
// Space: O(1)
 
typedef long long ll;

bool check(ll x, double tot, vector<ll>& A, int N) {
    tot += x;
    A[N-1] += x;
    double half_avg = (tot / (double) N) / 2.0;
    auto itr = upper_bound(A.begin(), A.end(), half_avg);

    A[N-1] -= x;

    return (itr-A.begin()) > N/2;
}

void solve(vector<ll>& A, int N) {
    sort(A.begin(), A.end());

    double tot = 0;
    for (int i = 0; i < N; i++)
        tot += A[i];

    const ll UPPER_BOUND = 1e9;
    ll l = 0, h = UPPER_BOUND;
    while (l <= h) {
        ll m = (h-l)/2 + l;
        if (check(m, tot, A, N)) {
            h = m-1;
        } else {
            l = m+1;
        }
    }

    cout << (l > UPPER_BOUND ? -1 : l) << endl;
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