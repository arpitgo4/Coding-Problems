// lostmap (https://open.kattis.com/problems/lostmap)
 
#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
 
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

void solve(vector<edge>& roads, int village_cnt) {
    DisjointSet ds(village_cnt);

    auto cmp = [&](const auto& t1, const auto& t2) {
        return get<2>(t1) < get<2>(t2);
    };

    sort(roads.begin(), roads.end(), cmp);

    for (auto& [u, v, w] : roads) {
        if (ds.root(u) != ds.root(v)) {
            ds.union_set(u, v);  
            cout << (u+1) << " " << (v+1) << endl;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int village_cnt;
    cin >> village_cnt;
    
    int u, v; 
    ll w;
    vector<edge> roads;
    for (int i = 0; i < village_cnt; i++) {
        for (int j = 0; j < village_cnt; j++) {
            cin >> w;
            roads.push_back({ i, j, w });
        }
    }

    solve(roads, village_cnt);
    
    return 0;
}