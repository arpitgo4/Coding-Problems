// Assignment to Segment (https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)
 
vector<int> ST, lazy;
vector<bool> marked;

void push(int i) {
    if (marked[i]) {
        lazy[2*i+2] = lazy[2*i+1] = lazy[i];
        marked[2*i+1] = marked[2*i+2] = true;
        marked[i] = false;
    }
}

void update(int l, int h, int i, int p, int q, int x) {
    if (l > h || p > q)
        return;
    if (l == p && h == q) {
        marked[i] = true;
        lazy[i] = x;
        return;
    }

    push(i);

    int m = (h-l)/2 + l;
    update(l, m, 2*i+1, p, min(m, q), x);
    update(m+1, h, 2*i+2, max(m+1, p), q, x);
}

int query(int l, int h, int i, int k) {
    if (l == h && l == k)
        return marked[i] ? lazy[i] : ST[i];

    push(i);

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
    lazy.assign(4*N, -1);
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