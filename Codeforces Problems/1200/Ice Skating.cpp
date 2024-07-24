// Ice Skating (https://codeforces.com/problemset/problem/217/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(1e6 * ⍺(N)) ~ O(⍺(N))
// Space: O(N)

/**
 * Could have Strongly Connected Components problem, if
 * there were defined directions for drifting.
 * 
 * Here, drifts are bidirectional, so all we need is a single
 * traversal and connect all drifts together under one DFS-tree
 * 
 * DSU and DFS are the candidate algorithms
 * 
 * DSU, initially some drifts may be connected together. Add them to
 * DSU tree/set.
 * We can incremently keep connecting more and more drifts and growing
 * the DSU tree/set until all drifts are connected.
 * 
 * Can come up with a function that can tell if two drifts can be connected
 * or not?
 */

typedef pair<int,int> coord;

const int MAX_BOUND = 1e3 + 1;

vector<vector<int>> G;
vector<int> P, S;

int drift_id;

void init_dsu(int N) {
    P.assign(N, -1);
    S.assign(N, 1);
    for (int i = 0; i < N; i++)
        P[i] = i;
}

int root(int x) {
    if (P[x] != x)
        return P[x] = root(P[x]);

    return P[x];
}

void union_set(int x, int y) {
    int root_x = root(x);
    int root_y = root(y);
    if (root_x != root_y) {
        if (S[root_x] < S[root_y])
        swap(root_x, root_y);

        P[root_y] = root_x;
        S[root_x] += S[root_y];
        S[root_y] = -1;
    }
}

void solve(vector<coord>& drifts, int N) {
    drift_id = 0;
    G.assign(MAX_BOUND, vector<int>(MAX_BOUND, -1));
    init_dsu(N);

    for (coord& c : drifts) {
        int x = c.first, y = c.second;
        G[x][y] = drift_id++;
    }

    for (int i = 0; i < MAX_BOUND; i++) {
        int prev_drift_id = -1;
        for (int j = 0; j < MAX_BOUND; j++) {
            if (G[i][j] != -1) {
                if (prev_drift_id == -1)
                    prev_drift_id = G[i][j];
                else union_set(G[i][j], prev_drift_id);
            }
        }
    }

    for (int i = 0; i < MAX_BOUND; i++) {
        int prev_drift_id = -1;
        for (int j = 0; j < MAX_BOUND; j++) {
            if (G[j][i] != -1) {
                if (prev_drift_id == -1)
                    prev_drift_id = G[j][i];
                else union_set(G[j][i], prev_drift_id);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
        if (P[i] == i)
            count++;

    cout << (count-1) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int x, y;
    vector<coord> drifts(N);
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        drifts[i] = { x, y };
    }

    solve(drifts, N);
    
    return 0;
}