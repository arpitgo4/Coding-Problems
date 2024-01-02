// Circumference of a Tree (https://codeforces.com/gym/102694/problem/A)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;

// Time: O(N)
// Space: O(N)

vector<vector<int>> T;

int diameter = 0;

int dfs(int u, int p) {
    int max_1 = 0, max_2 = 0;
    for (int v : T[u]) {
        if (v != p) {
            int dist = dfs(v, u) + 1;
            if (dist > max_1) {
                max_2 = max_1;
                max_1 = dist;
            } else if (dist > max_2)
                max_2 = dist;
        }
    }

    diameter = max({ diameter, max_1 + max_2, max_1 });

    return max_1;
}

void solve(vector<pair<int,int>>& edges, int N) {
    T.assign(N+1, vector<int>());
    for (pair<int,int>& e : edges) {
        int u = e.first, v = e.second;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    dfs(1, 1);

    cout << (3 * diameter);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int u, v;
    vector<pair<int,int>> edges(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> u >> v;
        edges[i] = { u, v };
    }

    solve(edges, N);
    
    return 0;
}