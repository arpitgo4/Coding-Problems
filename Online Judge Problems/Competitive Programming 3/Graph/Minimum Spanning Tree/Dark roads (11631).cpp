// Dark roads (11631)
 
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <tuple>
 
using namespace std;

// Time: O(VlogV)
// Space: O(V)
 
typedef tuple<int,int,int> edge;
 
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

void solve(vector<edge>& edges, int V, int E) {
    P.assign(V+1, -1);
    S.assign(V+1, 1);
    for (int i = 0; i <= V; i++)
        P[i] = i;

    sort(edges.begin(), edges.end(), [&](const edge& e1, const edge& e2) {
        return get<2>(e1) < get<2>(e2);
    });

    int old_cost = 0, new_cost = 0;
    int u, v, w;
    for (edge& e : edges) {
        tie (u, v, w) = e;
        old_cost += w;

        if (root(u) != root(v)) {
            union_set(u, v);
            new_cost += w;
        }
    }

    cout << (old_cost - new_cost) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    while (V != 0 && E != 0) {
        int u, v, w;
        vector<edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            edges[i] = { u, v, w };
        }

        solve(edges, V, E);

        cin >> V >> E;
    }

    return 0;
}