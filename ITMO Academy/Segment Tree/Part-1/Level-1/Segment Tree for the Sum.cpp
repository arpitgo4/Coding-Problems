// Segment Tree for the Sum (https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
// Time: O(N + QlogN)
// Space: O(N)
 
vector<ll> A, seg_tree;

ll update(int l, int h, int i, int idx, int val) {
    if (l == h && l == idx)
        return seg_tree[i] = A[idx] = val;
    
    int m = (h-l)/2 + l;
    if (idx <= m) {
        ll left = update(l, m, 2*i+1, idx, val);
        return seg_tree[i] = left + seg_tree[2*i+2];
    }
    else {
        ll right = update(m+1, h, 2*i+2, idx, val);
        return seg_tree[i] = seg_tree[2*i+1] + right;
    }
}

ll query(int l, int h, int i, int p, int q) {
    if (p > q)
        return 0;
    if (l == p && h == q)
        return seg_tree[i];

    int m = (h-l)/2 + l;
    return query(l, m, 2*i+1, p, min(q, m)) + 
            query(m+1, h, 2*i+2, max(m+1, p), q);
}

ll build_segment_tree(int l, int h, int i) {
    if (l == h)
        return seg_tree[i] = A[l];
    
    int m = (h-l)/2 + l;
    ll left = build_segment_tree(l, m, 2*i+1);
    ll right = build_segment_tree(m+1, h, 2*i+2);

    return seg_tree[i] = left + right;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    A.assign(N, 0);
    seg_tree.assign(4*N, 0);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    build_segment_tree(0, N-1, 0);

    int type, l, h;
    for (int i = 0; i < Q; i++) {
        cin >> type >> l >> h;
        if (type == 1)
            update(0, N-1, 0, l, h);
        else cout << query(0, N-1, 0, l, h-1) << endl;
    }
    
    return 0;
}