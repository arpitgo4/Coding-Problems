// Restructuring Company (https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(⍺(N))
// Space: O(N)

vector<int> P, R;

void init(int N) {
    P.assign(N+1, -1);
    R.assign(N+1, 0);
    for (int i = 0; i < N+1; i++)
        P[i] = i;
}
 
int root(int x) {
    if (P[x] != x)
        P[x] = root(P[x]);

    return P[x];
}

int union_set(int x, int y) {
    int root_x = root(x);
    int root_y = root(y);
    if (root_x == root_y)
        return root_x;

    if (R[root_x] < R[root_y])
        swap(root_x, root_y);

    // root_x is deeper set
    P[root_y] = P[root_x];
    R[root_x] = max(R[root_x], R[root_y] + 1);

    return root_x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    init(N);

    int type, x, y;
    for (int i = 0; i < Q; i++) {
        cin >> type >> x >> y;
        if (type == 1)
            union_set(x, y);
        else if (type == 2) {
            int merged_set = x;
            for (int i = x+1; i <= y; i++)
                merged_set = union_set(merged_set, i);
        } else                                                  // type == 3
            cout << (root(x) == root(y) ? "YES" : "NO") << endl;
    }
    
    return 0;
}