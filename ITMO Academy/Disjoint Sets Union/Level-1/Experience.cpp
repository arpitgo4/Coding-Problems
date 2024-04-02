 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O()
// Space: O()
 
#define INF LLONG_MAX
 
typedef long long ll;
 
vector<int> P, S, score, g_score;

void dsu_init(int N) {
    P.assign(N+1, -1);
    S.assign(N+1, 1);
    score.assign(N+1, 0);
    g_score.assign(N+1, 0);
    for (int i = 0; i < N+1; i++)
        P[i] = i;
}

int root(int x) {
    if (P[x] != x)
        P[x] = root(P[x]);

    return P[x];
}

void join(int x, int y) {
    int root_x = root(x);
    int root_y = root(y);
    if (root_x == root_y)
        return;

    if (S[root_x] < S[root_y])
        swap(root_x, root_y);

    P[root_y] = P[root_x];
    S[root_x] += S[root_y];
    S[root_y] = -1;
}

int get(int x) {
    int root_x = root(x);
    return score[x] + g_score[root_x];
}

void add(int x, int val) {
    int root_x = root(x);
    score[x] += val;
    g_score[root_x] += val; 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    dsu_init(N);

    string op;
    int x, y;
    for (int i = 0; i < Q; i++) {
        cin >> op >> x;
        if (op == "add") {
            cin >> y;
            add(x, y);
        } else if (op == "join") {
            cin >> y;
            join(x, y);
        } else
            cout << get(x) << endl;
    }
    
    return 0;
}