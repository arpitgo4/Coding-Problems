// UVa 11747 - Heavy Cycle Edges (https://onlinejudge.org/external/117/11747.pdf)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
 
using namespace std;
 
// Time: O(ElogE)
// Space: O(E)
 
typedef tuple<int,int,int> edge;

vector<int> P, S;

void init_dsu(int N) {
    P.assign(N+1, -1);
    S.assign(N+1, 1);
    for (int i = 0; i < N+1; i++) {
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

    auto cmp = [&](const edge& e1, const edge& e2) {
        return get<2>(e1) < get<2>(e2);
    };
    sort(edges.begin(), edges.end(), cmp);

    vector<int> weights;
    bool cycle_found = false;
    int u, v, w;
    for (edge& e : edges) {
        tie(u, v, w) = e;
        if (root(u) != root(v)) {
            union_set(u, v);
        } else {
            cycle_found = true;
            if (weights.empty()) {
                weights.push_back(w);
            } else if (weights.back() != w) {
                weights.push_back(w);
            }
        }
    }

    if (!cycle_found) {
        cout << "forest" << endl;
    } else {
        int N = weights.size();
        for (int i = 0; i < N; i++) {
            cout << weights[i];
            if (i != N-1)
                cout << " ";
        }
        cout << endl;
    }
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