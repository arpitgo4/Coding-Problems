// Learning Languages (https://codeforces.com/problemset/problem/277/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(⍺(N + M))
// Space: O(N + M)
 
/**
 * Problem can be modeled as Bipartite Graph,
 * With left side has all the employees and
 * right side has all the languages
 * 
 * If two employees connect with a same language in 
 * the right subset, then both can correspond
 * 
 * If an employee can reach `x` other employess via
 * languages subset then he can correspond with all of them
 * 
 * Two vertices belong to the same part if any path between them has an even length
 */

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

    init_dsu(N + M + 1);

    bool no_lang = true;
    int k, id;
    for (int i = 1; i <= N; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> id;
            union_set(i, N+id);
            no_lang = false;
        }
    }

    if (no_lang) {
        cout << N << endl;
        return 0;
    }

    vector<int> vis(N+1, 0);
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int root_x = root(i);
        if (vis[root_x] == 0)
            count++;

        vis[root_x] = 1;
    }

    cout << (count-1) << endl;
    
    return 0;
}