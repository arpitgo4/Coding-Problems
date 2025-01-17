// UVa 10653 - Bombs; NO they are Mines (https://onlinejudge.org/external/106/10653.pdf)
 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)
 
constexpr int INF = INT_MAX;

using grid_t = vector<vector<int>>;
using point_t = pair<int,int>;

void findShorestDistance(grid_t& grid, int row_cnt, int col_cnt, point_t& src, point_t& dest, grid_t& vis, grid_t& dist) {

    vector<point_t> moves{
        { -1, 0 },          // up
        { 1, 0 },           // down
        { 0, -1 },          // left
        { 0, 1 },           // right
    };

    queue<point_t> point_queue;

    if (grid[src.first][src.second] == INF)
        return;

    point_queue.push(src);
    vis[src.first][src.second] = 1;
    dist[src.first][src.second] = 0;

    while (!point_queue.empty()) {
        point_t curr = point_queue.front();
        point_queue.pop();

        int y = curr.first, x = curr.second;
        if (vis[y][x] == 2)
            continue;

        for (point_t move : moves) {
            int dy = move.first, dx = move.second;
            int ny = y + dy, nx = x + dx;
            if (nx >= 0 && nx < col_cnt && ny >= 0 && ny < row_cnt && vis[ny][nx] == 0 && grid[ny][nx] != INF) {
                point_queue.push({ ny, nx });
                vis[ny][nx] = 1;
                dist[ny][nx] = dist[y][x] + 1;
            }
        }

        vis[y][x] = 2;
    }
}

void solve(grid_t& grid, int row_cnt, int col_cnt, point_t& src, point_t& dest) {
    grid_t vis(row_cnt+1, vector<int>(col_cnt+1, 0));
    grid_t dist(row_cnt+1, vector<int>(col_cnt+1, INF));

    findShorestDistance(grid, row_cnt, col_cnt, src, dest, vis, dist);

    cout << dist[dest.first][dest.second] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int row_cnt, col_cnt;
    cin >> row_cnt >> col_cnt;
    
    while (row_cnt > 0 || col_cnt > 0) {
        int bomb_row_cnt;
        cin >> bomb_row_cnt;

        grid_t grid(row_cnt, vector<int>(col_cnt, 1));
        int row, bomb_cnt, bomb_col;
        for (int i = 0; i < bomb_row_cnt; i++) {
            cin >> row >> bomb_cnt;
            while (bomb_cnt--) {
                cin >> bomb_col;
                grid[row][bomb_col] = INF;
            }
        }

        int y, x;
        point_t src, dest;
        cin >> y >> x;
        src = { y, x };

        cin >> y >> x;
        dest = { y, x };

        solve(grid, row_cnt, col_cnt, src, dest);

        cin >> row_cnt >> col_cnt;
    }
    
    return 0;
}