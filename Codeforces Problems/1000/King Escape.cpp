// King Escape (https://codeforces.com/problemset/problem/1033/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * N)
// Space: O(N * N)
 
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

int dfs(int i, int j, pair<int,int>& target, int N) {
    if (i < 0 || i == N || j < 0 || j == N)
        return 0;
    if (i == target.first && j == target.second)
        return 1;
    if (G[i][j] == 1 || vis[i][j] != 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    vis[i][j] = 1;

    int res = 0;
    for (pair<int,int>& move : moves) {
        int x = move.first, y = move.second;
        res |= dfs(i+x, j+y, target, N);
    }

    vis[i][j] = 2;

    return dp[i][j] = res;
}

void mark_killer_cells(pair<int,int>& alice, int N) {
    int x = alice.first, y = alice.second;
    int i, j;
    
    i = x; j = y;
    while (i >= 0) G[i--][j] = 1;

    i = x; j = y;
    while (i < N) G[i++][j] = 1;

    i = x; j = y;
    while (j >= 0) G[i][j--] = 1;

    i = x; j = y;
    while (j < N) G[i][j++] = 1;

    i = x; j = y;
    while (i >= 0 && j >= 0) G[i--][j--] = 1;

    i = x; j = y;
    while (i < N && j < N) G[i++][j++] = 1;

    i = x; j = y;
    while (i < N && j >= 0) G[i++][j--] = 1;

    i = x; j = y;
    while (i >= 0 && j < N) G[i--][j++] = 1;
}

void solve(pair<int,int>& alice, pair<int,int>& bob, pair<int,int>& target, int N) {
    G.assign(N, vector<int>(N, 0));
    dp.assign(N, vector<int>(N, -1));
    vis.assign(N, vector<int>(N, 0));

    mark_killer_cells(alice, N);

    int can_reach = dfs(bob.first, bob.second, target, N);
    cout << (can_reach == 1 ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int i, j;
    pair<int,int> alice, bob, target;

    cin >> i >> j;
    alice = { i-1, j-1 };

    cin >> i >> j;
    bob = { i-1, j-1 };

    cin >> i >> j;
    target = { i-1, j-1 };

    solve(alice, bob, target, N);
    
    return 0;
}