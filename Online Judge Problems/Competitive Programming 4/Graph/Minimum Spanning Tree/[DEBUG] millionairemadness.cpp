// millionairemadness (https://open.kattis.com/problems/millionairemadness)
 
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <climits>
 
using namespace std;
 
// Time: O(N^2 + NlogN)
// Space: O(N^2)

const int INF = INT_MAX;

using grid_t = vector<vector<int>>;
using edge_t = tuple<int,int,int>;
using tree_edge_t = pair<int,int>;
using tree_t = vector<vector<tree_edge_t>>;

vector<pair<int,int>> moves{
    { -1, 0 },              // up
    { 1, 0 },               // down
    { 0, -1 },              // left
    { 0, 1 }                // right
};

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

int getCellIndex(int i, int j, int wid) {
    return i * wid + j;
}

void exploreVault(int i, int j, int len, int wid, grid_t& vault, grid_t& vis, vector<edge_t>& edges) {
    vis[i][j] = 1;
    
    for (auto& [di, dj] : moves) {
        int ni = i + di, nj = j + dj;
        if (ni >= 0 && ni < len && nj >= 0 && nj < wid && vis[ni][nj] == 0) {
            int from_idx = getCellIndex(i, j, wid);
            int to_idx = getCellIndex(ni, nj, wid);
            edges.push_back({ from_idx, to_idx, vault[i][j] - vault[ni][nj] });
            edges.push_back({ to_idx, from_idx, vault[ni][nj] - vault[i][j] });

            exploreVault(ni, nj, len, wid, vault, vis, edges);
        }
    }

    vis[i][j] = 2;
}

int maxLadderHeight(tree_t& tree, int curr_idx, int curr_par, int dest_idx, int max_height, int& max_ladder_height) {
    for (auto& [to, height] : tree[curr_idx]) {
        // cout << curr_idx << " -> " << to << " : " << height << endl;
        if (to != curr_par) {
            if (to == dest_idx) {
                cout << curr_idx << " -> " << to << " : " << height << endl;
                max_ladder_height = max(max_height, height);
            } else {
                maxLadderHeight(tree, to, curr_idx, dest_idx, max(max_height, height), max_ladder_height);
            }
        }
    }

    return -1;
}

void solve(grid_t& vault, int len, int wid) {
    int set_sz = len * wid;
    DisjointSet d_set(set_sz);

    grid_t vis(len+1, vector<int>(wid+1, 0));
    vector<edge_t> edges;
    exploreVault(0, 0, len, wid, vault, vis, edges);

    sort(edges.begin(), edges.end(), [&](const edge_t& e1, const edge_t& e2) {
        return get<2>(e1) < get<2>(e2);
    });

    vector<vector<tree_edge_t>> tree(set_sz+1, vector<tree_edge_t>());
    for (auto& [from, to, height] : edges) {
        if (d_set.root(from) != d_set.root(to)) {
            d_set.unionSet(from, to);
            tree[from].push_back({ to, height });
        }
    }

    int start_cell_idx = getCellIndex(0, 0, wid);
    int last_cell_idx = getCellIndex(len-1, wid-1, wid);
    int max_ladder_height;
    maxLadderHeight(tree, last_cell_idx, last_cell_idx, start_cell_idx, 0, max_ladder_height);

    cout << max_ladder_height << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int len, wid;
    cin >> len >> wid;
    
    grid_t vault(len, vector<int>(wid));
    for (int i = 0; i < len; i++)
        for (int j = 0; j < wid; j++)
            cin >> vault[i][j];

    solve(vault, len, wid);
    
    return 0;
}