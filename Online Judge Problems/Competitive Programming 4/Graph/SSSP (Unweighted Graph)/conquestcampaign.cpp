// conquestcampaign (https://open.kattis.com/problems/conquestcampaign)
 
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)

using point_t = pair<int,int>;
using matrix_t = vector<vector<int>>;

int minDaysToConquer(int row_cnt, int cell_cnt, vector<point_t>& weak_cells, int weak_cell_cnt, matrix_t& vis, matrix_t& day) {

    vector<point_t> moves{
        { -1, 0 },          // up
        { 1, 0 },           // down
        { 0, -1 },          // left
        { 0, 1 }            // right
    };

    queue<point_t> point_queue;
    for (auto& [ y, x ] : weak_cells) {
        point_queue.push({ y, x });
        vis[y][x] = 1;
        day[y][x] = 1;
    }

    int day_cnt = 1;
    while (!point_queue.empty()) {
        auto [ y, x ] = point_queue.front();
        point_queue.pop();

        if (vis[y][x] == 2)
            continue;

        day_cnt = max(day_cnt, day[y][x]);

        for (auto& [ dy, dx ] : moves) {
            int nx = x + dx, ny = y + dy;
            if (nx > 0 && nx <= cell_cnt && ny > 0 && ny <= row_cnt && vis[ny][nx] == 0) {
                point_queue.push({ ny, nx });
                vis[ny][nx] = 1;
                day[ny][nx] = day[y][x] + 1;
            }
        }

        vis[y][x] = 2;
    }

    return day_cnt;
}

void solve(int row_cnt, int cell_cnt, vector<point_t>& weak_cells, int weak_cell_cnt) {
    matrix_t vis(row_cnt+1, vector<int>(cell_cnt+1, 0));
    matrix_t day(row_cnt+1, vector<int>(cell_cnt+1, -1));

    int cnt = minDaysToConquer(row_cnt, cell_cnt, weak_cells, weak_cell_cnt, vis, day);
    cout << cnt << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int row_cnt, col_cnt, weak_cell_cnt;
    cin >> row_cnt >> col_cnt >> weak_cell_cnt;

    int x, y;
    vector<point_t> weak_cells(weak_cell_cnt);
    for (int i = 0; i < weak_cell_cnt; i++) {
        cin >> y >> x;
        weak_cells[i] = { y, x };
    }

    solve(row_cnt, col_cnt, weak_cells, weak_cell_cnt);
    
    return 0;
}