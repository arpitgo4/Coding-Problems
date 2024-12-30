// UVa 11631 - Dark Roads (https://onlinejudge.org/external/116/11631.pdf)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
 
using namespace std;
 
// Time: O(ElogE)
// Space: O(E)
 
typedef long long ll;
typedef tuple<int,int,int> edge;

vector<int> P, S;

void init_dsu(int N) {
    P.assign(N+1, -1);
    S.assign(N+1, 1);
    for (int i = 0; i <= N; i++) {
        P[i] = i;
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
    if (root_x != root_y) {
        if (S[root_x] < S[root_y])
            swap(root_x, root_y);

        P[root_y] = root_x;
        S[root_x] += S[root_y];
    }
}

void solve(vector<edge>& edges, int E, int V) {
    init_dsu(V);

    auto cmp = [&](const edge& t1, const edge& t2) {
        return get<2>(t1) < get<2>(t2);
    };
    sort(edges.begin(), edges.end(), cmp);

    ll og_tot = 0, tot = 0;
    int u, v, w;
    for (edge& e : edges) {
        tie(u, v, w) = e;
        og_tot += w;
        if (root(u) != root(v)) {
            tot += w;
            union_set(u, v);
        }
    }

    cout << (og_tot - tot) << endl;
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
    
        solve(edges, E, V);

        cin >> V >> E;
    }
    
    return 0;
}