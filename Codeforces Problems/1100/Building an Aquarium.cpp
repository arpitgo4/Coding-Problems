// Building an Aquarium (https://codeforces.com/problemset/problem/1873/E)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
/**
 * Can't just set the upper bound for binary search to the 
 * limit of the data type.
 * 
 * Based on the choosen value and logic there can be number-overflow 
 * in verifier function.
 * 
 * Always, calculate the lower and upper bounds based on the constraints 
 * for the problem
 */

typedef long long ll;

bool can_build(ll h, vector<ll>& A, ll N, ll W) {
    ll wtr_req = 0;
    for (ll a : A)
        wtr_req += max<ll>(0, h-a);

    return wtr_req <= W;
}

void solve(vector<ll>& A, ll N, ll W) {
    ll l = 1, h = 2'000'000'007;
    while (l <= h) {
        ll m = (h-l)/2 + l;
        if (can_build(m, A, N, W)) {
            l = m+1;
        } else {
            h = m-1;
        }
    }

    cout << h << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        ll N, W;
        cin >> N >> W;
        
        vector<ll> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
    
        solve(A, N, W);
    }
    
    return 0;
}