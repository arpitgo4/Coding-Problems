// C. Bitwise OR and AND (https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)

/**
 * Consider bitwise OR as addition operation
 * and bitwise AND as subtraction.
 */

#define lc 2*i+1
#define rc lc+1

vector<int> ST, lazy;
vector<bool> marked;

void push(int l, int h, int i) {
    if (marked[i]) {
        ST[lc] |= lazy[i];
        ST[rc] |= lazy[i];

        lazy[lc] |= lazy[i];
        lazy[rc] |= lazy[i];
        marked[lc] = marked[rc] = true;

        lazy[i] = 0;
        marked[i] = true;
    }
}

void update(int l, int h, int i, int p, int q, int x) {
    if (p > q)
        return;
    if (l == p && h == q) {
        ST[i] |= x;
        lazy[i] |= x;
        marked[i] = true;
        return;
    }

    push(l, h, i);
    int m = (h-l)/2 + l;
    update(l, m, lc, p, min(m, q), x);
    update(m+1, h, rc, max(m+1, p), q, x);

    ST[i] = ST[lc] & ST[rc];
}

int query(int l, int h, int i, int p, int q) {
    if (p > q)
        return (1 << 31) - 1;                   // This will set first 30 bits, so that AND operation with this becomes no-op
    if (l == p && h == q)
        return ST[i];
    
    push(l, h, i);
    int m = (h-l)/2 + l;
    return query(l, m, lc, p, min(m, q)) & query(m+1, h, rc, max(m+1, p), q);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    ST.assign(4*N, 0);
    lazy.assign(4*N, 0);
    marked.assign(4*N, false);

    int type, l, h, x;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> l >> h >> x;
            update(0, N-1, 0, l, h-1, x);
        } else {
            cin >> l >> h;
            int val = query(0, N-1, 0, l, h-1);
            cout << val << endl;
        }
    }
    
    return 0;
}