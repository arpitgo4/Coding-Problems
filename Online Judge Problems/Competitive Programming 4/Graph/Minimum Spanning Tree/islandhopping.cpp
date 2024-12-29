// islandhopping (https://open.kattis.com/problems/islandhopping)
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
 
using namespace std;
 
// Time: O(V * V)
// Space: O(V * V)
 
typedef pair<double,double> coord;
typedef tuple<int,int,double> edge;

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

double dist(coord& c1, coord& c2) {
    double diff_x = (c2.first - c1.first);
    double diff_y = (c2.second - c1.second);
    return sqrt((diff_x * diff_x) + (diff_y * diff_y));
}

void solve(vector<coord>& A, int V) {
    init_dsu(V);

    vector<edge> edges;
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
        if (root(i) != root(j)) {
            tot_w += w;
            union_set(i, j);
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
        vector<coord> A(V);
        for (int i = 0; i < V; i++) {
            cin >> x >> y;
            A[i] = { x, y };
        }
    
        solve(A, V);
    }
    
    return 0;
}