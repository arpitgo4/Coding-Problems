// A. Addition and Minimum (https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)

/**
 * We need Minimum Segment Tree with Range Additions
 */

#define INF LLONG_MAX

typedef long long ll;

vector<ll> ST, lazy;
vector<bool> marked;
 
// propogate the update one level down to preserve time complexity
void push(int i) {
    if (marked[i]) {
        ST[i] += lazy[i];                           // update the minimum value at internal node
        lazy[2*i+1] += lazy[i];
        lazy[2*i+2] += lazy[i];
        marked[2*i+1] = marked[2*i+2] = true;

        lazy[i] = 0;
        marked[i] = false;
    }
}

void update(int l, int h, int i, int p, int q, ll x) {
    if (l > h || p > q)
        return;
    if (l == p && h == q) {
        lazy[i] += x;
        marked[i] = true;
        return;
    }

    push(i);

    int m = (h-l)/2 + l;
    update(l, m, 2*i+1, p, min(q, m), x);
    update(m+1, h, 2*i+2, max(m+1, p), q, x);

    // propogate the update upwards till root
    ST[i] = min<ll>(ST[2*i+1] + lazy[2*i+1], ST[2*i+2] + lazy[2*i+2]);
}

ll query(int l, int h, int i, int p, int q) {
    if (l > h || p > q)
        return INF;
    if (l == p && h == q)
        return ST[i] + lazy[i];

    push(i);

    int m = (h-l)/2 + l;
    return min<ll>(
        query(l, m, 2*i+1, p, min(q, m)),
        query(m+1, h, 2*i+2, max(m+1, p), q)
    );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    ST.assign(4*N, 0);
    lazy.assign(4*N, 0);
    marked.assign(4*N, false);

    int type, l, h, k;
    ll x;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> l >> h >> x;
            update(0, N-1, 0, l, h-1, x);
        } else {
            cin >> l >> h;
            ll val = query(0, N-1, 0, l, h-1);
            cout << val << endl;
        }
    }
    
    return 0;
}