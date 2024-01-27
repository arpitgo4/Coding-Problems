// Number of Minimums on a Segment (https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C)
 
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
 
using namespace std;
 
/**
 * NOTE: code is working, but needs optimization to remove passing around pair obejcts
 * Test cases are giving TLE. 
 * Instead of having pair objects in tree, build 2 trees for minimum number and 
 * it's count values.
*/

// Time: O(N + QlogN)
// Space: O(N)

vector<int> A;
vector<pair<int,int>> seg_tree; 

pair<int,int> merge(pair<int,int> left, pair<int,int> right) {
    int min_element_1, min_element_2;
    int count_1, count_2;

    tie(min_element_1, count_1) = left;
    tie(min_element_2, count_2) = right;

    if (min_element_1 < min_element_2)
        return left;
    else if (min_element_2 < min_element_1)
        return right;
    else return { min_element_1, count_1 + count_2 };
}

void update(int l, int h, int i, int idx, int val) {
    if (l == h && l == idx) {
        A[idx] = val;
        seg_tree[i] = { A[idx], 1 };
        return;
    }

    int m = (h-l)/2 + l;
    if (idx <= m)
        update(l, m, 2*i+1, idx, val);
    else update(m+1, h, 2*i+2, idx, val);
    
    seg_tree[i] = merge(seg_tree[2*i+1], seg_tree[2*i+2]);
}

pair<int,int> query(int l, int h, int i, int p, int q) {
    if (p > q)
        return { INT_MAX, 0 };
    if (l == h)
        return seg_tree[i];

    int m = (h-l)/2 + l;
    return merge(
        query(l, m, 2*i+1, p, min(q, m)), 
        query(m+1, h, 2*i+2, max(m+1, p), q)
    );
}

void build_segment_tree(int l, int h, int i) {
    if (l == h) {
        seg_tree[i] = { A[l], 1 };
        return;
    }

    int m = (h-l)/2 + l;
    build_segment_tree(l, m, 2*i+1);
    build_segment_tree(m+1, h, 2*i+2);
    seg_tree[i] = merge(seg_tree[2*i+1], seg_tree[2*i+2]);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    A.assign(N, 0);
    seg_tree.assign(4*N, { INT_MAX, 0 });

    for (int i = 0; i < N; i++)
        cin >> A[i];

    build_segment_tree(0, N-1, 0);

    int type, idx, v, l, h;
    for (int i = 0; i < M; i++) {
        cin >> type;
        if (type == 1) {
            cin >> idx >> v;
            update(0, N-1, 0, idx, v);
        } else {
            cin >> l >> h;
            auto p = query(0, N-1, 0, l, h-1);
            cout << p.first << " " << p.second << endl; 
        }
    }
    
    return 0;
}