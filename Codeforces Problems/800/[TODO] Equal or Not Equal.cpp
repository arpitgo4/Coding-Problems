// Equal or Not Equal (https://codeforces.com/problemset/problem/1620/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O()
// Space: O()
 
vector<int> P, S;

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

        P[root_y] = P[root_x];
        S[root_x] += S[root_y];
        S[root_y] = -1; 
    }
}

void solve(string& S) {
    int N = S.length()
    init_dsu(N);

    for (int i = 0; i < N; i++) {
        int x = i;
        int y = (i+1) % N;
        if (S[i] == 'E') {
            if (root(x) != root(y)) {
                union_set(x, y);
            }
        }
        
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        solve(S);
    }
    
    return 0;
}