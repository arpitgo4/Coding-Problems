// First element at least X (https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/C)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)

vector<int> A, seg_tree;

int first_at_least_x(int l, int h, int i, int x) {
    if (l == h)
        return seg_tree[i] >= x ? l : -1;

    int m = (h-l)/2 + l;
    if (seg_tree[2*i+1] >= x)
        return first_at_least_x(l, m, 2*i+1, x);
    else return first_at_least_x(m+1, h, 2*i+2, x);
}

int update(int l, int h, int i, int idx, int val) {
    if (l == h && l == idx)
        return seg_tree[i] = A[idx] = val;
    
    int m = (h-l)/2 + l;
    if (idx <= m)
        update(l, m, 2*i+1, idx, val);
    else update(m+1, h, 2*i+2, idx, val);

    return seg_tree[i] = max(seg_tree[2*i+1], seg_tree[2*i+2]);
}

int build_seg_tree(int l, int h, int i) {
    if (l == h)
        return seg_tree[i] = A[l];

    int m = (h-l)/2 + l;
    build_seg_tree(l, m, 2*i+1);
    build_seg_tree(m+1, h, 2*i+2);
    return seg_tree[i] = max(seg_tree[2*i+1], seg_tree[2*i+2]);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    A.assign(N, -1);
    seg_tree.assign(4*N, -1);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    build_seg_tree(0, N-1, 0);

    int type, idx, val, x;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> idx >> val;
            update(0, N-1, 0, idx, val);
        }
        else {
            cin >> x;
            cout << first_at_least_x(0, N-1, 0, x) << endl;
        }
    }   
    
    return 0;
}