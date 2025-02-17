// minspantree (https://open.kattis.com/problems/minspantree)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)

using ll = long long;
using edge = tuple<int,int,ll>;
using tree_edge = pair<int,int>;

class DisjointSet {
public:
    DisjointSet(int sz) {
        parent_.assign(sz+1, -1);
        sz_.assign(sz+1, 1);
        iota(parent_.begin(), parent_.end(), 0);
    }

    int root(int x) {
        if (parent_[x] != x)
            parent_[x] = root(parent_[x]);

        return parent_[x];
    }

    void union_set(int x, int y) {
        int root_x = root(x);
        int root_y = root(y);
        if (root_x != root_y) {
            if (sz_[root_x] < sz_[root_y])
                swap(root_x, root_y);

            parent_[root_y] = root_x;
            sz_[root_x] += sz_[root_y];
        }
    }
private:
    vector<int> parent_, sz_;
};
 
void solve(vector<edge>& edges, int edge_cnt, int node_cnt) {
    DisjointSet ds(node_cnt);

    auto cmp = [&](const auto& t1, const auto& t2) {
        return get<2>(t1) < get<2>(t2);
    };
    sort(edges.begin(), edges.end(), cmp);

    vector<tree_edge> mst_edges;
    ll mst_weight = 0;
    for (auto& [u, v, w] : edges) {
        if (ds.root(u) != ds.root(v)) {
            ds.union_set(u, v);
            mst_weight += w;
            mst_edges.push_back({ u, v });
        }
    }

    int root_cnt = 0;
    for (int u = 0; u < node_cnt; u++) {
        if (ds.root(u) == u) {
            root_cnt++;
        }
    }

    if (root_cnt > 1) {
        cout << "Impossible" << endl;
        return;
    }

    sort(mst_edges.begin(), mst_edges.end(), [&](const auto& p1, const auto& p2) {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first < p2.first;
    });

    cout << mst_weight << endl;
    for (auto& [u, v] : mst_edges) {
        cout << u << " " << v << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int node_cnt, edge_cnt;
    cin >> node_cnt >> edge_cnt;
    
    while (node_cnt > 0 || edge_cnt > 0) {
        int u, v;
        ll w;
        vector<edge> edges(edge_cnt);
        for (int i = 0; i < edge_cnt; i++) {
            cin >> u >> v >> w;
            edges[i] = { u, v, w };    
        }

        solve(edges, edge_cnt, node_cnt);
        
        cin >> node_cnt >> edge_cnt;
    }
    
    return 0;
}