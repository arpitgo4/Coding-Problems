// Experience (https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
// Time: O(N * Q)
// Space: O(N)

const int MAX = 2 * 1e5;

vector<int> P, S;
vector<ll> XP;

void init_dsu() {
    P.assign(MAX+1, 0);
    XP.assign(MAX+1, 0);
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

void addXP(int x, int v) {
    int root_x = root(x);
    for (int i = 0; i < MAX+1; i++)
        if (root(i) == root_x)
            XP[i] += v;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    init_dsu();

    string type;
    int x, y, v;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type == "join") {
            cin >> x >> y;
            union_set(x, y);
        } else if (type == "add") {
            cin >> x >> v;
            addXP(x, v);
        } else {
            cin >> x;
            cout << XP[x] << endl;
        }
    }
    
    return 0;
}