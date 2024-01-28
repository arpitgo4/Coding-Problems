// First element at least X - 2 (https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/D)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
/**
 * Tightening time complexity by adding additional checks if (seg_tree[left/right] >= x), 
 * helped passing the time limits for the problem.
 * 
 * Although Big-O time complexity still remains same, but eliminator checks saved time
 * by not diving unnecessary subtree
*/

// Time: O(N + QlogN)
// Space: O(N)

vector<int> A, seg_tree;
 
int first_at_least_x_p(int l, int h, int i, int x, int p) {
    if (seg_tree[i] < x)
        return -1;
    if (l == h)
        return seg_tree[i] >= x && l >= p ? l : -1;

    int m = (h-l)/2 + l;
    if (p <= m) {                                                    // search in left & right segments. left first
        int res = first_at_least_x_p(l, m, 2*i+1, x, p);
        if (res != -1)
            return res;
            
        return first_at_least_x_p(m+1, h, 2*i+2, x, p);
    } else                                                          // p > m, search in right segment only
        return first_at_least_x_p(m+1, h, 2*i+2, x, p);
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

    int type, idx, val, x, p;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> idx >> val;
            update(0, N-1, 0, idx, val);
        }
        else {
            cin >> x >> p;
            cout << first_at_least_x_p(0, N-1, 0, x, p) << endl;
        }
    }      
    
    return 0;
}