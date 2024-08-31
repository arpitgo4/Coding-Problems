// Addition to Segment (https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N + QlogN)
// Space: O(N)

typedef long long ll;

vector<ll> ST, lazy;
vector<bool> marked;

void push(int l, int h, int i) {
    if (marked[i]) {
        int m = (h-l)/2 + l;
        ST[2*i+1] += lazy[i] * (m-l+1);
        ST[2*i+2] += lazy[i] * (h-m);

        lazy[2*i+1] += lazy[i];
        lazy[2*i+2] += lazy[i];
        marked[2*i+1] = marked[2*i+2] = true;
        
        lazy[i] = 0;
        marked[i] = false;
    }
}

void update(int l, int h, int i, int p, int q, ll x) {
    if (p > q)
        return;
    if (l == p && h == q) {
        ST[i] += x;
        marked[i] = true;
        lazy[i] += x;
        return;
    }

    push(l, h, i);
    int m = (h-l)/2 + l;
    update(l, m, 2*i+1, p, min(q, m), x);
    update(m+1, h, 2*i+2, max(m+1, p), q, x);

    ST[i] = ST[2*i+1] + ST[2*i+2];
}

ll query(int l, int h, int i, int k) {
    if (l > h)
        return 0;
    if (l == h && l == k)
        return ST[i];
    
    push(l, h, i);
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
    lazy.assign(4*N, 0);
    marked.assign(4*N, false);

    int type, l, h;
    ll x;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> l >> h >> x;
            update(0, N-1, 0, l, h-1, x);
        } else {
            cin >> l;
            ll val = query(0, N-1, 0, l);
            cout << val << endl;
        }
    }
    
    return 0;
}