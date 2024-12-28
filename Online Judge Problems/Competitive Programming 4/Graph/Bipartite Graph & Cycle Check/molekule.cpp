// molekule (https://open.kattis.com/problems/molekule)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
typedef pair<int,int> edge;

vector<vector<int>> T;
vector<int> color;

void dfs(int u, int p, int c) {
    color[u] = c;
    for (int v : T[u]) {
        if (v != p) {
            dfs(v, u, (c+1) % 2);
        }
    }
}

void solve(vector<edge>& edges, int N) {
    T.assign(N+1, vector<int>());
    color.assign(N+1, -1);
    for (auto& [u, v] : edges) {
        T[u].push_back(v);
        T[v].push_back(u);
    }

    dfs(1, 1, 0);

    for (auto& [u, v] : edges) {
        cout << color[u] << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int u, v;
    vector<edge> edges(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> u >> v;
        edges[i] = { u, v };
    }

    solve(edges, N);
    
    return 0;
}