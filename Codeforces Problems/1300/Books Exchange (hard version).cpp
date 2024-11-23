// Books Exchange (hard version) (https://codeforces.com/problemset/problem/1249/B2)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N * ⍺(N))
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

void solve(vector<int>& P, int N) {
    init_dsu(N);

    for (int i = 0; i < N; i++)
        union_set(i+1, P[i]);

    for (int i = 0; i < N; i++)
        cout << S[root(i+1)] << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> P(N);
        for (int i = 0; i < N; i++)
            cin >> P[i];
    
        solve(P, N);
    }
    
    return 0;
}