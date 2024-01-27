// Segment Tree for the Minimum (https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)
 
vector<int> A, seg_tree;

int update(int l, int h, int i, int idx, int val) {
    if (l == h && l == idx)
        return seg_tree[i] = A[idx] = val;
    
    int m = (h-l)/2 + l;
    if (idx <= m) {
        int left = update(l, m, 2*i+1, idx, val);
        return seg_tree[i] = min(left, seg_tree[2*i+2]);
    } else {
        int right = update(m+1, h, 2*i+2, idx, val);
        return seg_tree[i] = min(seg_tree[2*i+1], right);
    }
}

int query(int l, int h, int i, int p, int q) {
    if (p > q)
        return INT_MAX;
    if (l == p && h == q)
        return seg_tree[i];
    
    int m = (h-l)/2 + l;
    return min(
        query(l, m, 2*i+1, p, min(q, m)),
        query(m+1, h, 2*i+2, max(p, m+1), q)
    );
}

int build_segment_tree(int l, int h, int i) {
    if (l == h)
        return seg_tree[i] = A[l];

    int m = (h-l)/2 + l;
    return seg_tree[i] = min(
        build_segment_tree(l, m, 2*i+1),
        build_segment_tree(m+1, h, 2*i+2)
    );
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    A.assign(N, INT_MAX);
    seg_tree.assign(4*N, INT_MAX);

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