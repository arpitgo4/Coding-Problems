// Spanning Tree (https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/E)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
 
using namespace std;
using ll = long long;
 
// Time: O(VlogV)
// Space: O(V)

vector<int> P, S;

void init(int N) {
    P.assign(N+1, -1);
    S.assign(N+1, 1);
    for (int i = 0; i < N+1; i++)
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

    if (S[root_x] < S[root_y])
        swap(x, y);

    // root_x has bigger set
    P[root_y] = P[root_x];
    S[root_x] += S[root_y];
    S[root_y] = -1;
}

void solve(int V, int E, vector<tuple<int,int,ll>>& edges) {
    sort(edges.begin(), edges.end(), [&](auto& t1, auto& t2) {
        return get<2>(t1) < get<2>(t2);
    });

    init(V);

    ll cost = 0;
    int u, v; ll w;
    for (auto& edge : edges) {
        tie(u,v,w) = edge;
        if (root(u) != root(v)) {
            union_set(u, v);
            cost += w;
        }
    }

    cout << cost;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    int u, v; ll w;
    vector<tuple<int,int,ll>> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }

    solve(V, E, edges);
    
    return 0;
}