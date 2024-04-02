// Computer Game (https://codeforces.com/problemset/problem/1598/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * 2) ~ O(N)
// Space: O(N * 2) ~ O(N)
 
vector<vector<int>> G, dp, vis;

vector<pair<int,int>> moves{
    { 1, 0 },               // up
    { -1, 0 },              // down
    { 0, -1 },              // left
    { 0, 1 },               // right
    { 1, -1 },              // up-left
    { 1, 1 },               // up-right
    { -1, -1 },             // down-left
    { -1, 1 },              // down-right
};

int dfs(int i, int j, int N) {
    if (i < 0 || i == 2 || j < 0 || j == N)
        return 0;
    if (i == 1 && j == N-1)
        return 1;
    if (G[i][j] == 1 || vis[i][j] != 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    vis[i][j] = 1;                            // vis array helps to ignore cycles in the graph

    int res = 0;
    for (pair<int,int>& move : moves) {
        int x = move.first, y = move.second;
        res |= dfs(i + x, j + y, N);
    }

    vis[i][j] = 2;

    return dp[i][j] = res;
}

void solve(int N) {
    int can_reach = dfs(0, 0, N);
    cout << (can_reach == 1 ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        G.assign(2, vector<int>(N, 0));
        vis.assign(2, vector<int>(N, 0));
        dp.assign(2, vector<int>(N, -1));

        string line;
        for (int i = 0; i < 2; i++) {
            cin >> line;
            for (int j = 0; j < N; j++) {
                if (line[j] == '1')
                    G[i][j] = 1;
            }
        }

        solve(N);
    }   
    
    return 0;
}