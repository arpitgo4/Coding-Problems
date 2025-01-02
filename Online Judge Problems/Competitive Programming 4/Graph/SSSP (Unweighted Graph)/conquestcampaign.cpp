// conquestcampaign (https://open.kattis.com/problems/conquestcampaign)
 
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)
 
typedef pair<int,int> coord;
typedef tuple<int,int,int> state;

vector<vector<int>> vis;

vector<coord> moves{
    { -1, 0 },          // up
    { 1, 0 },           // down
    { 0, -1 },          // left
    { 0, 1 }            // right
};

int bfs(vector<coord>& S, int N, int M) {
    queue<state> q;
    for (auto& [i, j] : S) {
        q.push({ i, j, 1 });
        vis[i][j] = 1;
    }

    int max_days = 1;
    while (!q.empty()) {
        auto [i, j, d] = q.front();
        q.pop();

        if (vis[i][j] == 2)
            continue;

        max_days = max(max_days, d);

        for (auto& [di, dj] : moves) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < N && nj >= 0 && nj < M && vis[ni][nj] == 0) {
                q.push({ ni, nj, d+1 });
                vis[ni][nj] = 1;
            }
        }

        vis[i][j] = 2;
    }

    return max_days;
}

void solve(vector<coord>& S, int N, int M) {
    vis.assign(N+1, vector<int>(M+1, 0));
    int day_cnt = bfs(S, N, M);

    cout << day_cnt << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, src_cnt;
    cin >> N >> M >> src_cnt;

    int x, y;
    vector<coord> S(src_cnt);
    for (int i = 0; i < src_cnt; i++) {
        cin >> x >> y;
        S[i] = { x-1, y-1 };
    }

    solve(S, N, M);
    
    return 0;
}