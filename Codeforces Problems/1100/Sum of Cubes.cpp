// Sum of Cubes (https://codeforces.com/problemset/problem/1490/C)
 
#include <iostream>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(1)
 
/**
 * Each a & b can have max value of 1e4, as
 * cube(a) + cube(b) = 1e12
 * 
 * Based on above constraints O(NlogN) algorithm
 * will work for the problem.
 * 
 * We need an efficient algorithm to find the 
 * cube root for a given number. Binary search
 * can be used here.
 */

typedef long long ll;

ll cube(ll x) {
    return x * x * x;
}

ll cube_root(ll x) {
    if (x <= 0)
        return 0;

    ll l = 1, h = 10'000;
    while (l <= h) {
        ll m = (h-l)/2 + l;
        if (cube(m) == x) {
            return m;
        } else if (cube(m) > x) {
            h = m-1;
        } else {                                    // cube(m) < x
            l = m+1;
        }
    }

    return 0;
}

void solve(ll x) {
    bool found = false;
    for (ll a = 1; a <= 10'000; a++) {
        ll diff = x - cube(a);
        ll b = cube_root(diff);

        if (b != 0 && (cube(a) + cube(b)) == x) {
            found = true;
            break;
        }
    }

    cout << (found ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        ll x;
        cin >> x;
    
        solve(x);
    }
    
    return 0;
}