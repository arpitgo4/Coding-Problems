// UVa 11228 - Transportation (https://onlinejudge.org/external/112/11228.pdf)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
 
using namespace std;
 
// Time: O(V^2 * logV)
// Space: O(V^2)

typedef pair<int,int> coord;
typedef tuple<int,int,double> edge;

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

double dist(coord& c1, coord& c2) {
    double diff_x = (c2.first - c1.first);
    double diff_y = (c2.second - c1.second);
    return sqrt((diff_x * diff_x) + (diff_y * diff_y));
}

void solve(vector<coord>& A, int V, int R) {
    init_dsu(V);

    vector<edge> edges;
    for (int i = 0; i < V; i++) {
        for (int j = i+1; j < V; j++) {
            double w = dist(A[i], A[j]);
            edges.push_back({ i, j, w });
        }
    }

    auto cmp = [&](const edge& e1, const edge& e2) {
        return get<2>(e1) < get<2>(e2);
    };
    sort(edges.begin(), edges.end(), cmp);

    int state_cnt = 1;
    double road = 0.0, rail = 0.0;
    int u, v; double w;
    for (edge& e : edges) {
        tie(u, v, w) = e;
        if (root(u) != root(v)) {
            union_set(u, v);
            
            if (w > R) {
                state_cnt++;
                rail += w;
            } else {
                road += w;    
            }
        }
    }

    cout << state_cnt << " " << round(road) << " " << round(rail) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    int test_idx = 0;
    while (T--) {
        int V, R;
        cin >> V >> R;

        int x, y;
        vector<coord> A(V);
        for (int i = 0; i < V; i++) {
            cin >> x >> y;
            A[i] = { x, y };
        }
    
        cout << "Case #" << (test_idx+1) << ": ";
        solve(A, V, R);

        test_idx++;
    }
    
    return 0;
}