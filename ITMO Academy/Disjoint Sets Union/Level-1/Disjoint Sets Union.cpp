// Disjoint Sets Union (https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(log*(N))
// Space: O(N)

const int MAX = 1e5;

vector<int> P, S;

void init_dsu() {
    P.assign(MAX+1, 0);
    S.assign(MAX+1, 1);
    for (int i = 0; i < MAX+1; i++)
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
    if (root_x == root_y)
        return;

    if (S[root_x] > S[root_y]) {
        P[root_y] = P[root_x];
        S[root_x] += S[root_y];
        S[root_y] = -1;
    } else {
        P[root_x] = P[root_y];
        S[root_y] += S[root_x];
        S[root_x] = -1;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    init_dsu();

    string type;
    int x, y;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == "union") {
            cin >> x >> y;
            union_set(x, y);
        } else {
            cin >> x >> y;
            cout << (root(x) == root(y) ? "YES" : "NO") << endl;
        }
    }
    
    return 0;
}