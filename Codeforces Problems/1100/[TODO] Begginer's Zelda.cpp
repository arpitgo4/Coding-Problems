// Begginer's Zelda (https://codeforces.com/problemset/problem/1905/B)
 
#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
 
using namespace std;
 
// Time: O()
// Space: O()

/**
 * iteratively till (T.size != 1),
 *  1. diameter path of tree
 *  2. modify tree
*/
 
typedef pair<int,int> edge;
 
const int MAX_N = 1e8;

vector<set<int>> T;
vector<int> depth, removed, P;
int node_count, node_id;

void print_vector(vector<int>& A, int N) {
    for (int i = 1; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}

void dfs(int u, int p, int dep) {
    depth[u] = dep;
    P[u] = p;
    for (int v : T[u]) {
        if (v != p)
            dfs(v, u, dep+1);
    }
}

int max_depth_node() {
    int root = -1, max_depth = -1;
    for (int u = 1; u < MAX_N; u++) {
        if (!removed[u]) {
            if (max_depth < depth[u]) {
                max_depth = depth[u];
                root = u;
            }
        }
    }

    return root;
}

void solve(vector<edge>& edges, int N) {
    T.assign(MAX_N, set<int>());
    removed.assign(MAX_N, false);
    node_count = N;
    node_id = N;
    for (auto& [u, v] : edges) {
        T[u].insert(v);
        T[v].insert(u);
    }

    int count = 0;
    while (node_count > 1) {
        depth.assign(MAX_N, 0);
        P.assign(MAX_N, -1);
        for (int u = 1; u < MAX_N; u++)
            if (!removed[u]) {
                dfs(u, u, 0);
                break;
            }

        cout << "Depth: "; print_vector(depth, node_id);

        int root = max_depth_node();
        cout << "Root: " << root << endl; 

        depth.assign(MAX_N, 0);
        P.assign(MAX_N, -1);
        dfs(root, root, 0);

        int x = node_id++;
        T[x] = set<int>();
        node_count++;
        removed[x] = false;

        int u = max_depth_node();
        cout << "Leaf: " << u << endl;
        while (u != root) {
            for (int v : T[u]) {                    // remove edges from existing node on diameter
                T[x].insert(v); T[v].insert(x);
                T[v].erase(u);
            }

            cout << "Path: " << u << endl; 

            removed[u] = true;
            node_count--;

            u = P[u];
        }
        
        count++;
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int u, v;
        vector<edge> edges(N-1);
        for (int i = 0; i < N-1; i++) {
            cin >> u >> v;
            edges[i] = { u, v };
        }

        solve(edges, N);
    }
    
    return 0;
}