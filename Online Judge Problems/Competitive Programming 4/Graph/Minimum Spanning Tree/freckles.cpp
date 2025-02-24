// freckles (https://open.kattis.com/problems/freckles)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
// Time: O(N^2 * logN)
// Space: O(N^2)

using coord_t = pair<double,double>;
using edge_t = tuple<int,int,double>;

class DisjointSet {
public:
    DisjointSet(int set_sz) {
        parent_.assign(set_sz+1, -1);
        sz_.assign(set_sz+1, 1);
        iota(parent_.begin(), parent_.end(), 0);
    }

    int root(int x) {
        if (x != parent_[x])
            parent_[x] = root(parent_[x]);

        return parent_[x];
    }

    void unionSet(int x, int y) {
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

double getEuclidDist(coord_t& c1, coord_t& c2) {
    double x_dist = (c2.first - c1.first) * (c2.first - c1.first);
    double y_dist = (c2.second - c1.second) * (c2.second - c1.second);
    return sqrt(x_dist + y_dist);
}

void solve(vector<coord_t>& freckles, int freckle_cnt) {
    vector<edge_t> edges;
    for (int i = 0; i < freckle_cnt; i++) {
        for (int j = i+1; j < freckle_cnt; j++) {
            edges.push_back({ i, j, getEuclidDist(freckles[i], freckles[j]) });
        }
    }

    sort(edges.begin(), edges.end(), [&](const edge_t& e1, const edge_t& e2) {
        return get<2>(e1) < get<2>(e2);
    });

    double total_dist = 0.0;
    DisjointSet ds(freckle_cnt);
    for (auto& [from, to, dist] : edges) {
        if (ds.root(from) != ds.root(to)) {
            ds.unionSet(from, to);
            total_dist += dist;
        }
    }

    cout << fixed << setprecision(2) << total_dist << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cnt;
    cin >> test_cnt;
    
    int i = 0;
    while (test_cnt--) {
        if (i > 0)
            cout << endl;

        int freckle_cnt;
        cin >> freckle_cnt;
        
        double x, y;
        vector<coord_t> freckles(freckle_cnt);
        for (int i = 0; i < freckle_cnt; i++) {
            cin >> x >> y;
            freckles[i]= { x, y };
        }
    
        solve(freckles, freckle_cnt);
        i++;
    }
    
    return 0;
}