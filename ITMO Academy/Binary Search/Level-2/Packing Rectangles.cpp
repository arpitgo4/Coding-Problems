// Packing Rectangles (https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
using ll = long long;

// Time: O(logN)
// Space: O(1)

bool can_fit(ll x, ll w, ll h, ll n) {
    ll box_count = (x/w) * (x/h);
    return box_count >= n;
}

void solve(ll W, ll H, ll N) {
    ll l = 0, h = 1;
    while (!can_fit(h, W, H, N))
        h *= 2;

    while (l <= h) {
        ll m = (h-l)/2 + l;

        if (can_fit(m, W, H, N))
            h = m-1;
        else l = m+1;
    }

    cout << l;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll W, H, N;
    cin >> W >> H >> N;

    solve(W, H, N);
    
    return 0;
}