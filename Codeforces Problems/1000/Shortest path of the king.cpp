// Shortest path of the king (https://codeforces.com/problemset/problem/3/A)
 
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)

/**
 * TODO: complete the implementation!
 */

const int MAX_N = 8;
vector<vector<int>> vis(MAX_N, vector<int>(MAX_N, 0));
vector<vector<tuple<int,int,string>>> P(MAX_N, vector<pair<int,int>>(MAX_N));
 
void bfs(int sx, int sy, int tx, int ty) {
    queue<pair<int,int>> q({{ sx, sy }});
    vis[sx][sy] = 1;

    while (!q.empty()) {
        auto [ i, j ] = q.front();
        q.pop();

        if (vis[i][j] == 2)
            continue;
        vis[i][j] = 2;

        if (j-1 >= 0 && vis[i][j-1] == 0) {
            q.push({ i, j-1 });
            vis[i][j-1] = 1;
            P[i][j-1] = { i, j, "L" };
        }
        if (j+1 < MAX_N && vis[i][j+1] == 0) {
            q.push({ i, j+1 });
            vis[i][j+1] = 1;
            P[i][j+1] = { i, j, "R" };
        }
        if (i-1 >= 0 && vis[i-1][j] == 0) {
            q.push({ i-1, j });
            vis[i-1][j] = 1;
            P[i-1][j] = { i, j, "U" };
        }
        if (i+1 < MAX_N && vis[i+1][j] == 0) {
            q.push({ i+1, j });
            vis[i+1][j] = 1;
            P[i+1][j] = { i, j, "D" };
        }
        if (j-1 >= 0 && i-1 >= 0 && vis[i-1][j-1] == 0) {
            q.push({ i-1, j-1 });
            vis[i-1][j-1] = 1;
            P[i-1][j-1] = { i, j, "LU" };
        }
        if (j-1 >= 0 && i+1 < MAX_N && vis[i+1][j-1] == 0) {
            q.push({ i+1, j-1 });
            vis[i+1][j-1] = 1;
            P[i+1][j-1] = { i, j, "LD" };
        }
        if (j+1 < MAX_N && i-1 >= 0 && vis[i-1][j+1] == 0) {
            q.push({ i-1, j+1 });
            vis[i-1][j+1] = 1;
            P[i-1][j+1] = { i, j, "RU" };
        }
        if (j+1 < MAX_N && i+1 < MAX_N && vis[i+1][j+1] == 0) {
            q.push({ i+1, j+1 });
            vis[i+1][j+1] = 1;
            P[i+1][j+1] = { i, j, "RD" };
        }
    }
}

void solve(char sx, int sy, char tx, int ty) {
    bfs(sx-'A', MAX_N-sy, tx-'A', MAX_N-ty);

    int count = 0;
    vector<string> path;
    pair<int,int> curr = { tx, ty };
    while (curr.first != sx && ) {

    }


    cout << count << endl;
    for (string& s : path)
        cout << s << endl;
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char sx; int sy;
    cin >> sx >> sy;

    char tx; int ty;
    cin >> tx >> ty;

    solve(sx, sy, tx, ty);
    
    return 0;
}