// Shortest path of the king (https://codeforces.com/problemset/problem/3/A)
 
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
 
using namespace std;
 
typedef long long ll;
 
// Time: O(N * N)
// Space: O(8 * 8) ~ O(1)
 
vector<vector<int>> vis;
vector<vector<string>> movements;
vector<vector<pair<int,int>>> par;

const vector<tuple<int,int,string>> moves{
    {-1, 0, "U"},                    // up
    {1, 0, "D"},                     // down
    {0, -1, "L"},                    // left
    {0, 1, "R"},                     // right
    {-1, -1, "LU"},                  // left-up
    {1, -1, "LD"},                   // left-down
    {-1, 1, "RU"},                   // right-up
    {1, 1, "RD"},                    // right-down
};

void print_path(int i, int j, int count) {
    int p_i = i, p_j = j;
    while (count--) {
        cout << movements[p_i][p_j] << endl;
        p_i = par[p_i][p_j].first;
        p_j = par[p_i][p_j].second;
    }
}

void solve(int src_i, int src_j, int dest_i, int dest_j) {
    cout << src_i << " " << src_j << endl;
    cout << dest_i << " " << dest_j << endl;

    vis.assign(8, vector<int>(8, 0));
    par.assign(8, vector<pair<int,int>>(8, {-1,-1}));
    movements.assign(8, vector<string>(8, ""));

    queue<tuple<int,int,int,string,int,int>> q;
    q.push({ src_i, src_j, 0, "", -1, -1 });

    int i, j, count, p_i, p_j; string move;
    while (!q.empty()) {
        tie(i, j, count, move, p_i, p_j) = q.front();
        q.pop();

        if (vis[i][j] == 1)
            continue;
        vis[i][j] = 1;

        movements[i][j] = move;
        par[i][j] = { p_i, p_j };
        if (i == dest_i && j == dest_j) {
            cout << count << endl;
            print_path(i, j, count);
            break;
        }

        int x, y; string ticker;
        for (auto& t : moves) {
            tie(x, y, ticker) = t;
            int new_x = i + x;
            int new_y = j + y;
            if ((new_x >= 0 && new_x < 8) && (new_y >= 0 && new_y < 8) && vis[new_x][new_y] == 0)
                q.push({ new_x, new_y, count+1, ticker, i, j });
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string source, dest;
    cin >> source >> dest;

    int src_j = source[0] - 'a';
    int src_i = 7 - (dest[1] - '1');

    int dest_j = dest[0] - 'a';
    int dest_i = 7 - (dest[1] - '1');

    solve(src_i, src_j, dest_i, dest_j);
    
    return 0;
}