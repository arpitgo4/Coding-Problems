// Segment with the Maximum Sum (https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;

/**
 * Interesting problem!! 
 * Will solve it later.
*/

vector<ll> A, seg_tree;

ll update(int l, int h, int i, int idx, int val) {
    if (l == h && l == idx)
        return seg_tree[i] = A[idx] = val;

    int m = (h-l)/2 + l;
    if (idx <= m)
        update(l, m, 2*i+1, idx, val);
    else update(m+1, h, 2*i+2, idx, val);

    return seg_tree[i] = seg_tree[2*i+1] + seg_tree[2*i+2];
}

ll build_segment_tree(int l, int h, int i) {
    if (l == h)
        return seg_tree[i] = A[l];

    int m = (h-l)/2 + l;
    return seg_tree[i] = min(
        build_segment_tree(l, m, 2*i+1),
        build_segment_tree(m+1, h, 2*i+2)
    );
}

ll max_sum_segment(int l, int h, int i) {
    return -1;
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
    cout << max_sum_segment(0, N-1, 0) << endl;

    int type, idx, val;
    for (int i = 0; i < Q; i++) {
        cin >> type >> idx >> val;
        
        update(0, N-1, 0, l, h);
        cout << max_sum_segment(0, N-1, 0) << endl;
    }
    
    return 0;
}