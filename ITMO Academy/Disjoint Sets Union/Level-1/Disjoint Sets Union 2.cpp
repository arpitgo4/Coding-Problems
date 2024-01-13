// Disjoint Sets Union 2 (https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O(log*(N))
// Space: O(N)

const int MAX_N = 3 * 1e5;

vector<int> P, S, MAX, MIN;

void init_dsu() {
    P.assign(MAX_N+1, 0);
    S.assign(MAX_N+1, 1);
    MAX.assign(MAX_N+1, 0);
    MIN.assign(MAX_N+1, 0);
    for (int i = 0; i < MAX_N+1; i++) {
        P[i] = i;
        MAX[i] = i;
        MIN[i] = i;
    }
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
        MIN[root_x] = min({ MIN[root_x], MIN[root_y], x, y });
        MAX[root_x] = max({ MAX[root_x], MAX[root_y], x, y });
    } else {
        P[root_x] = P[root_y];
        S[root_y] += S[root_x];
        S[root_x] = -1;
        MIN[root_y] = min({ MIN[root_x], MIN[root_y], x, y });
        MAX[root_y] = max({ MAX[root_x], MAX[root_y], x, y });
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
            cin >> x;
            int root_x = root(x);
            cout << MIN[root_x] << " " << MAX[root_x] << " " << S[root_x] << endl;
        }
    }
    
    return 0;
}