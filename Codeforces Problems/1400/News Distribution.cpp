// News Distribution (https://codeforces.com/problemset/problem/1167/C)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O((N + M) * ⍺(N))
// Space: O(N)

vector<int> P, S;

void init_dsu(int N) {
    P.assign(N+1, -1);
    S.assign(N+1, 1);
    for (int i = 0; i <= N; i++)
        P[i] = i;
}

int root(int x) {
    if (P[x] != x)
        P[x] = root(P[x]);

    return P[x];
}

void union_set(int x, int y) {
    int root_x = root(x);
    int root_y = root(y);
    if (root_x != root_y) {
        if (S[root_x] < S[root_y])
            swap(root_x, root_y);

        P[root_y] = P[root_x];
        S[root_x] += S[root_y];
        S[root_y] = -1;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    init_dsu(N);

    int k, x, y;
    for (int i = 0; i < M; i++) {
        cin >> k;
        if (k != 0)
            cin >> x;
        for (int j = 1; j < k; j++) {
            cin >> y;
            union_set(x, y);
            x = y;
        }
    }

    for (int i = 1; i <= N; i++) {
        int root_i = root(i);
        int comp_sz = S[root_i];
        cout << comp_sz << " ";
    }
    cout << endl;
    
    return 0;
}