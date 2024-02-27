// No refuel (https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/G)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)

typedef tuple<int,int,int> tree_edge;

vector<int> P, S;

int root(int x) {
    if (P[x] != x)
        P[x] = root(P[x]);

    return P[x];
}

void merge(int x, int y) {
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

int mst(vector<tree_edge>& edges, int V) {
    int max_dist = 0;
    
    sort(edges.begin(), edges.end(), [&](const tree_edge& e1, const tree_edge& e2) {
        return get<2>(e1) < get<2>(e2);
    });

    int u, v, w;
    for (tree_edge& edge : edges) {
        tie(u,v,w) = edge;
        if (root(u) != root(v)) {
            merge(u, v);
            max_dist = max(max_dist, w);
        }
    }

    return max_dist;
}

void solve(vector<tree_edge>& edges, int V, int E) {
    P.assign(V+1, 0);
    S.assign(V+1, 1);
    for (int i = 0; i <= V; i++)
        P[i] = i;

    int max_dist = mst(edges, V);

    cout << max_dist << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    int u, v, w;
    vector<tree_edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }

    solve(edges, V, E);
    
    return 0;
}