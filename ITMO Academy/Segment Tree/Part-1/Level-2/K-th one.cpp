// K-th one (https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)
 
vector<int> A, seg_tree;

// sum == (k+1) -> return index
// sum > (k+1) -> move left
// sum < (k+1) -> move right, decrease k by seg_tree[2*i+1] (left segment sum)
int kth_one(int l, int h, int i, int k) {
    if (l == h)
        return seg_tree[i] != 1 ? -1 : l;               // for invalid kth values
    
    int m = (h-l)/2 + l;
    if (seg_tree[2*i+1] >= (k+1))
        return kth_one(l, m, 2*i+1, k);
    else return kth_one(m+1, h, 2*i+2, k-seg_tree[2*i+1]);
}

int update(int l, int h, int i, int idx) {
    if (l == h && l == idx)
        return seg_tree[i] = A[idx] = !A[idx];
    
    int m = (h-l)/2 + l;
    if (idx <= m)
        update(l, m, 2*i+1, idx);
    else update(m+1, h, 2*i+2, idx);

    return seg_tree[i] = seg_tree[2*i+1] + seg_tree[2*i+2];
}

int build_seg_tree(int l, int h, int i) {
    if (l == h)
        return seg_tree[i] = A[l];

    int m = (h-l)/2 + l;
    build_seg_tree(l, m, 2*i+1);
    build_seg_tree(m+1, h, 2*i+2);
    return seg_tree[i] = seg_tree[2*i+1] + seg_tree[2*i+2];
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

    int type, k;
    for (int i = 0; i < Q; i++) {
        cin >> type >> k;
        if (type == 1)
            update(0, N-1, 0, k);
        else cout << kth_one(0, N-1, 0, k) << endl;
    }
    
    return 0;
}