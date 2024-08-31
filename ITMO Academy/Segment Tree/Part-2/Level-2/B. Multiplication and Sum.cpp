 // B. Multiplication and Sum (https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/B)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)

/**
 * We need,
 * 1. Sum Segment Tree
 * 2. Range Multiplication Updates
 */

#define lc 2*i+1
#define rc lc+1

typedef long long ll;

const ll MOD = 1e9 + 7;

vector<ll> A, ST, lazy;
vector<bool> marked;

void build_seg_tree(int l, int h, int i) {
    if (l > h)
        return;
    if (l == h) {
        ST[i] = A[l];
        return;
    }

    int m = (h-l)/2 + l;
    build_seg_tree(l, m, lc);
    build_seg_tree(m+1, h, rc);

    ST[i] = (ST[lc] + ST[rc]) % MOD;
}

void push(int l, int h, int i) {
    if (marked[i]) {
        ST[lc] = ST[lc] * lazy[i] % MOD;
        ST[rc] = ST[rc] * lazy[i] % MOD;

        lazy[lc] = lazy[lc] * lazy[i] % MOD;
        lazy[rc] = lazy[rc] * lazy[i] % MOD;
        marked[lc] = marked[rc] = true;

        lazy[i] = 1;
        marked[i] = false;
    }
}

void update(int l, int h, int i, int p, int q, ll x) {
    if (p > q)
        return;
    if (l == p && h == q) {
        ST[i] = ST[i] * x % MOD;
        lazy[i] = lazy[i] * x % MOD;
        marked[i] = true;
        return;
    }

    push(l, h, i);
    int  m = (h-l)/2 + l;
    update(l, m, lc, p, min(m, q), x);
    update(m+1, h, rc, max(m+1, p), q, x);

    ST[i] = (ST[lc] + ST[rc]) % MOD; 
}

ll query(int l, int h, int i, int p, int q) {
    if (p > q)
        return 0;
    if (l == p && h == q)
        return ST[i];

    push(l, h, i);
    int m = (h-l)/2 + l;
    return (query(l, m, lc, p, min(q, m)) + query(m+1, h, rc, max(m+1, p), q)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    A.assign(N, 1);
    ST.assign(4*N, 0);
    lazy.assign(4*N, 1);
    marked.assign(4*N, false);

    build_seg_tree(0, N-1, 0);

    int type, l, h;
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