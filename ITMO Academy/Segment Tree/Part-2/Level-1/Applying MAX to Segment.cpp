// Applying MAX to Segment (https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/B)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)
 
/**
 * We cannot decide for a semgent based on the aggregated (max)
 * value in the internal node of segment tree that all values can
 * be replaced with update value `x`.
 * 
 * So, we just have to make sure, if (ST[i] < x) then for sure all 
 * values are <x in the segment and lazy flag can be marked for
 * lazy propogation otherwise, we have to anyways mark the lazy flag
 * and let `x` propogate downwards when we get further `update` or 
 * `query` operations on the same segment/subsegment. With lazy propogation
 * we will not do unnecessary updates in the tree, but only the required ones
 * and all leaf nodes will get to decide if there value can be updated
 * with the applied update value `x`.
 */

vector<int> ST, lazy;
vector<bool> marked;

void push(int l, int h, int i) {
    if (marked[i]) {
        ST[2*i+1] = max(ST[2*i+1], lazy[i]);
        ST[2*i+2] = max(ST[2*i+2], lazy[i]);

        lazy[2*i+1] = max(lazy[2*i+1], lazy[i]);
        lazy[2*i+2] = max(lazy[2*i+2], lazy[i]);
        marked[2*i+1] = marked[2*i+2] = true;

        lazy[i] = 0;
        marked[i] = false;
    }
}

void update(int l, int h, int i, int p, int q, int x) {
    if (p > q)
        return;
    if (l == p && h == q) {
        ST[i] = max(ST[i], x);
        lazy[i] = max(lazy[i], x);
        marked[i] = true;

        return;
    }

    push(l, h, i);
    int m = (h-l)/2 + l;
    update(l, m, 2*i+1, p, min(m, q), x);
    update(m+1, h, 2*i+2, max(m+1, p), q, x);

    ST[i] = max(ST[2*i+1], ST[2*i+2]);
}

int query(int l, int h, int i, int k) {
    if (l > h)
        return 0;
    if (l == h && l == k)
        return ST[i];

    push(l, h, i);
    int m = (h-l)/2 + l;
    if (k <= m)
        return query(l, m, 2*i+1, k);
    else return query(m+1, h, 2*i+2, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    ST.assign(4*N, 0);
    lazy.assign(4*N, 0);
    marked.assign(4*N, false);

    int type, l, h, k, x;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> l >> h >> x;
            update(0, N-1, 0, l, h-1, x);
        } else {
            cin >> k;
            int val = query(0, N-1, 0, k);
            cout << val << endl;
        }
    }
    
    return 0;
}