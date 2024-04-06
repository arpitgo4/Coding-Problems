// Party (https://codeforces.com/problemset/problem/115/A)

#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

typedef pair<int,int> edge;

vector<vector<int>> T;
vector<int> depth, roots;

void dfs(int u, int p, int dep) {
    depth[u] = dep;
    for (int v : T[u]) {
        if (v != p)
            dfs(v, u, dep+1);
    }
}

void solve(vector<edge>& edges, int N) {
    T.assign(N+1, vector<int>());
    depth.assign(N+1, 0);
    for (edge& e : edges) {
        int u = e.first, v = e.second;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    for (int u : roots)
        dfs(u, -1, 1);

    int count = 0;
    for (int d : depth)
        count = max(count, d);

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N; 

    int u, v;
    vector<edge> edges;
    for (int u = 1; u <= N; u++) {
        cin >> v;
        if (v == -1)
            roots.push_back(u);
        else edges.push_back({ u, v });
    }

    solve(edges, N);
    
    return 0;
}
