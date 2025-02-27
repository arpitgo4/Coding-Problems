// hopscotch50 (https://open.kattis.com/problems/hopscotch50)
 
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <climits>
 
using namespace std;
 
// Time: O(ElogV)
// Space: O(V)
 
const int INF = INT_MAX;

using grid_t = vector<vector<int>>;
using coord_t = pair<int,int>;
using tile_index_t = unordered_map<int,vector<coord_t>>;
using queue_state_t = pair<int,coord_t>;

int getTileId(coord_t& coord, int grid_sz) {
    return coord.second + (coord.first * grid_sz);
}

int getDistance(coord_t& c1, coord_t& c2) {
    return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}

void findShortestPath(
    tile_index_t& tile_index, 
    grid_t& grid, 
    int src_tile, 
    int grid_sz, 
    int tile_num_cnt, 
    vector<int>& dist) {

    auto cmp = [&](const queue_state_t& s1, const queue_state_t& s2) {
        return s1.first > s2.first;
    };
    priority_queue<queue_state_t, vector<queue_state_t>, decltype(cmp)> pq(cmp);

    vector<int> vis(grid_sz * grid_sz, 0);
    for (coord_t& src_coord : tile_index[src_tile]) {
        int tile_id = getTileId(src_coord, grid_sz);
        dist[tile_id] = 0;
        pq.push({ dist[tile_id], src_coord });
    }

    while (!pq.empty()) {
        auto [ _, curr_coord ] = pq.top();
        pq.pop();

        int curr_tile_id = getTileId(curr_coord, grid_sz);
        auto [ i, j ] = curr_coord;
        int curr_tile_val = grid[i][j];

        if (vis[curr_tile_id] != 0)
            continue;

        vis[curr_tile_id] = 1;
        
        int next_tile_val = curr_tile_val + 1;
        if (next_tile_val > tile_num_cnt)
            continue;

        for (coord_t& next_coord : tile_index[next_tile_val]) {
            int next_tile_id = getTileId(next_coord, grid_sz);
            int manh_dist = getDistance(curr_coord, next_coord);
            if (dist[next_tile_id] > dist[curr_tile_id] + manh_dist) {
                dist[next_tile_id] = dist[curr_tile_id] + manh_dist;
                pq.push({ dist[next_tile_id], next_coord });
            }
        }

        vis[curr_tile_id] = 2;
    }
}

void solve(grid_t& grid, int grid_sz, int tile_num_cnt) {
    tile_index_t tile_index;
    for (int i = 0; i < grid_sz; i++) {
        for (int j = 0; j < grid_sz; j++) {
            int tile = grid[i][j];
            if (tile_index.find(tile) == tile_index.end()) {
                tile_index.insert({ tile, *new vector<coord_t>() });
            }

            tile_index[tile].push_back({ i, j });
        }
    }

    vector<int> dist(grid_sz * grid_sz, INF);
    findShortestPath(tile_index, grid, 1, grid_sz, tile_num_cnt, dist);

    int min_dist = INF;
    for (coord_t& dest_coord : tile_index[tile_num_cnt]) {
        int dest_tile_id = getTileId(dest_coord, grid_sz);
        min_dist = min(min_dist, dist[dest_tile_id]);
    } 

    cout << (min_dist == INF ? -1 : min_dist) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int grid_sz, tile_num_cnt;
    cin >> grid_sz >> tile_num_cnt;
    
    grid_t grid(grid_sz, vector<int>(grid_sz));
    for (int i = 0; i < grid_sz; i++) {
        for (int j = 0; j < grid_sz; j++) {
            cin >> grid[i][j];    
        }
    }

    solve(grid, grid_sz, tile_num_cnt);
    
    return 0;
}