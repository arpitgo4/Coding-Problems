// Addition to Segment (https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;

int N;
vector<ll> seg_tree, A;

void print_vector(vector<ll>& A) {
    for (int a : A)
        cout << a << " ";
    cout << endl;
}

void update(int l, int h, int i, int p, int q, ll val) {
    // cout << l << ", " << h << ", " << p << ", " << q << endl;
    if (l == p && h == q) {
        seg_tree[i] += val;
        return;
    }

    int m = (h-l)/2 + l;
    if (p <= m && q <= m)
        update(l, m, 2*i+1, p, min(m, q), val);
    else if (p > m && q > m)
        update(m+1, h, 2*i+2, max(m+1, p), q, val);
    else {
        update(l, m, 2*i+1, p, m, val);
        update(m+1, h, 2*i+2, m+1, q, val);
    }

    seg_tree[i] = seg_tree[2*i+1] + seg_tree[2*i+2];
}

ll query(int l, int h, int i, int idx) {
    if (l == h && l == idx)
        return seg_tree[i];

    int m = (h-l)/2 + l;
    if (idx <= m)
        return seg_tree[i] + query(l, m, 2*i+1, idx);
    else return seg_tree[i] + query(m+1, h, 2*i+2, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Q;
    cin >> N >> Q;

    A.assign(N, 0);
    seg_tree.assign(4*N, 0);

    int type, l, h, v;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> l >> h >> v;
            update(0, N-1, 0, l, h-1, v);
            cout << endl;
            print_vector(seg_tree);
            cout << endl;
        } else {
            cin >> l;
            cout << query(0, N-1, 0, l) << endl;
        }
    }
    
    return 0;
}