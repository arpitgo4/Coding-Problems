// Number of Minimums on a Segment (https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C)
 
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
 
using namespace std;
 
/**
 * NOTE: code is working, but needs optimization to remove passing around pair objects
 * Test cases are giving TLE. 
 * Instead of having pair objects in tree, build 2 trees for minimum number and 
 * it's count values.
*/

// Time: O(N + QlogN)
// Space: O(N)

#define INF INT_MAX

vector<int> ST_min, ST_cnt, A;

void merge(int i) {
    int left_idx = 2*i+1, right_idx = left_idx + 1;

    if (ST_min[left_idx] < ST_min[right_idx]) {
        ST_min[i] = ST_min[left_idx];
        ST_cnt[i] = ST_cnt[left_idx];
    }
    else if (ST_min[right_idx] < ST_min[left_idx]) {
        ST_min[i] = ST_min[right_idx];
        ST_cnt[i] = ST_cnt[right_idx];
    }
    else {
        ST_min[i] = ST_min[left_idx];
        ST_cnt[i] = ST_cnt[left_idx] + ST_cnt[right_idx];
    };
}

void update(int l, int h, int i, int idx, int val) {
    if (l == h && l == idx) {
        A[idx] = val;
        ST_min[i] = A[idx];
        ST_cnt[i] = 1;
        return;
    }

    int m = (h-l)/2 + l;
    if (idx <= m)
        update(l, m, 2*i+1, idx, val);
    else update(m+1, h, 2*i+2, idx, val);
    
    merge(i);
}

void query(int l, int h, int i, int p, int q, int& res_min, int& res_cnt) {
    if (l > h || p > q)
        return;
    if (l == p && h == q) {
        if (res_min > ST_min[i]) {
            res_min = ST_min[i];
            res_cnt = ST_cnt[i];
        } else if (res_min == ST_min[i])
            res_cnt += ST_cnt[i];

        return;
    }

    int m = (h-l)/2 + l;
    query(l, m, 2*i+1, p, min(q, m), res_min, res_cnt);
    query(m+1, h, 2*i+2, max(m+1, p), q, res_min, res_cnt);
}

void build_segment_tree(int l, int h, int i) {
    if (l == h) {
        ST_min[i] = A[l];
        ST_cnt[i] = 1;
        return;
    }

    int m = (h-l)/2 + l;
    build_segment_tree(l, m, 2*i+1);
    build_segment_tree(m+1, h, 2*i+2);

    merge(i);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    A.assign(N, 0);
    ST_min.assign(4*N, INF);
    ST_cnt.assign(4*N, 0);
    
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
            int res_min = INF, res_cnt = 0;
            query(0, N-1, 0, l, h-1, res_min, res_cnt);
            cout << res_min << " " << res_cnt << endl; 
        }
    }
    
    return 0;
}