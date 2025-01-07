// islandhopping (https://open.kattis.com/problems/islandhopping)
 
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
 
using namespace std;
 
// Time: O(V * V)
// Space: O(V * V)
 
typedef pair<double,double> Point;
typedef tuple<int,int,double> Edge;

class DisjointSet {
public:
    DisjointSet(int set_sz) {
        parent_.assign(set_sz+1, -1);
        sz_.assign(set_sz+1, 1);
        iota(parent_.begin(), parent_.end(), 0);
    }

    int root(int x) {
        if (parent_[x] != x)
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
    vector<int> parent_;
    vector<int> sz_;
};

double dist(Point& c1, Point& c2) {
    double diff_x = (c2.first - c1.first);
    double diff_y = (c2.second - c1.second);
    return sqrt((diff_x * diff_x) + (diff_y * diff_y));
}

void solve(vector<Point>& A, int V) {
    DisjointSet d_set(V);

    vector<Edge> edges;
    for (int i = 0; i < V; i++) {
        for (int j = i+1; j < V; j++) {
            double w = dist(A[i], A[j]);
            edges.push_back({ i, j, w });
        }
    }

    auto cmp = [&](const auto& t1, const auto& t2) {
        return get<2>(t1) < get<2>(t2);
    };
    sort(edges.begin(), edges.end(), cmp);

    double tot_w = 0.0;
    for (auto& [i, j, w] : edges) {
        if (d_set.root(i) != d_set.root(j)) {
            tot_w += w;
            d_set.unionSet(i, j);
        }
    }

    cout << fixed << setprecision(3) << tot_w << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int V;
        cin >> V;
        
        double x, y;
        vector<Point> A(V);
        for (int i = 0; i < V; i++) {
            cin >> x >> y;
            A[i] = { x, y };
        }
    
        solve(A, V);
    }
    
    return 0;
}