// drivingrange (https://open.kattis.com/problems/drivingrange)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <tuple>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
using ll = long long;
using edge = tuple<int,int,ll>;

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

void solve(vector<edge>& roads, int road_cnt, int city_cnt) {
    DisjointSet ds(city_cnt);

    sort(roads.begin(), roads.end(), [&](const auto& t1, const auto& t2) {
        return get<2>(t1) < get<2>(t2);
    });

    ll max_distance = 0;
    for (auto& [u, v, w] : roads) {
        if (ds.root(u) != ds.root(v)) {
            ds.union_set(u, v);
            max_distance = max<ll>(max_distance, w);
        }
    }

    int root_cnt = 0;
    for (int u = 0; u < city_cnt; u++) {
        if (ds.root(u) == u) {
            root_cnt++;    
        }
    }

    if (root_cnt > 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << max_distance << endl;    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int city_cnt, road_cnt;
    cin >> city_cnt >> road_cnt;

    int u, v; ll w;
    vector<edge> roads(road_cnt);
    for (int i = 0; i < road_cnt; i++) {
        cin >> u >> v >> w;
        roads[i] = { u, v, w };
    }

    solve(roads, road_cnt, city_cnt);
    
    return 0;
}