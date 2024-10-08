// A. Addition and Minimum (https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)

/**
 * We need Minimum Segment Tree with Range Additions
 */

#define INF LLONG_MAX
#define lc 2*i+1
#define rc lc+1

typedef long long ll;

vector<ll> ST, lazy;
vector<bool> marked;

void push(int l, int h, int i) {
    if (marked[i]) {
        ST[lc] += lazy[i];
        ST[rc] += lazy[i];

        lazy[lc] += lazy[i];
        lazy[rc] += lazy[i];
        marked[lc] = marked[rc] = true;

        lazy[i] = 0;
        marked[i] = false;
    }
}

void update(int l, int h, int i, int p, int q, ll x) {
    if (p > q)
        return;
    if (l == p && h == q) {
        ST[i] += x;
        lazy[i] += x;
        marked[i] = true;
        return;
    }

    push(l, h, i);
    int m = (h-l)/2 + l;
    update(l, m, lc, p, min(q, m), x);
    update(m+1, h, rc, max(m+1, p), q, x);

    ST[i] = min(ST[lc], ST[rc]);
}

ll query(int l, int h, int i, int p, int q) {
    if (p > q)
        return INF;
    if (l == p && h == q)
        return ST[i];

    push(l, h, i);
    int m = (h-l)/2 + l;
    return min(
        query(l, m, lc, p, min(m, q)),
        query(m+1, h, rc, max(m+1, p), q)
    );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    ST.assign(4*N, 0);
    lazy.assign(4*N, 0);
    marked.assign(4*N, false);

    int type, l, h, k;
    ll x;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> l >> h >> x;
            update(0, N-1, 0, l, h-1, x);
        } else {
            cin >> l >> h;
            ll val = query(0, N-1, 0, l, h-1);
            cout << val << endl;
        }
    }
    
    return 0;
}