// Re-connecting Computer Sites (908)
 
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <tuple>
#include <algorithm>
 
using namespace std;
 
/**
 * Added string's getline() to exit program on empty line
 * 
 * TODO: add input parsing logic in main()
*/

// Time: O((N+M)log(N+M) * ⍺(N+M))
// Space: O(N+M)

#define INF LLONG_MAX
 
typedef long long ll;
typedef tuple<int,int,ll> edge;
 
vector<int> P, S;

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

    if (S[root_x] < S[root_y])
        swap(root_x, root_y);

    P[root_y] = P[root_x];
    S[root_x] += S[root_y];
    S[root_y] = -1;
}

void solve(vector<edge>& T, int N, vector<edge>& new_lines, int K, vector<edge>& old_lines, int M) {
    P.assign(N+M+1, -1);
    S.assign(N+M+1, 1);
    for (int i = 0; i < N+M+1; i++)
        P[i] = i;

    ll old_cost = 0;
    for (edge& e : T)
        old_cost += get<2>(e);

    vector<edge> all_lines(N+M+1);
    all_lines.insert(all_lines.end(), new_lines.begin(), new_lines.end());
    all_lines.insert(all_lines.end(), old_lines.begin(), old_lines.end());

    sort(all_lines.begin(), all_lines.end(), [&](edge& e1, edge& e2) {
        return get<2>(e1) < get<2>(e2);
    });

    int u, v, c;
    ll new_cost = 0;
    for (edge& e : all_lines) {
        tie(u, v, c) = e;
        if (root(u) != root(v)) {
            union_set(u, v);
            new_cost += c;
        }
    }

    // cout << old_cost << endl;
    // cout << new_cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    int N, K, M;
    while(true) {
        getline(cin, line);
        if (line.empty())
            break;

        int u, v; ll c;
        vector<edge> T(N-1);
        for (int i = 0; i < N-1; i++) {
            cin >> u >> v >> c;
            T[i] = { u, v, c };
        }

        cin >> K;
        vector<edge> new_lines(K);
        for (int i = 0; i < K; i++) {
            cin >> u >> v >> c;
            new_lines[i] = { u, v, c };
        }

        cin >> M;
        vector<edge> old_lines(M);
        for (int i = 0; i < M; i++) {
            cin >> u >> v >> c;
            old_lines[i] = { u, v, c };
        }

        solve(T, N, new_lines, K, old_lines, M);
    }
    
    return 0;
}