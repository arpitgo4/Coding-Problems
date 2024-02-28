// DZY Loves Chessboard (https://codeforces.com/problemset/problem/445/A)
 
#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O()
// Space: O()

#define INF INT_MAX
 
typedef long long ll;
 
vector<vector<int>> G;
bool solution_found = false;
bool board_printed = false;

vector<pair<int,int>> moves{
    { -1, 0 },                  // up
    { 1, 0 },                   // down
    { 0, -1 },                  // left
    { 0, 1 },                   // right
};

void print_board(int N, int M) {
    if (board_printed)
        return;
    if (!solution_found)
        return;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x = G[i][j];
            if (x == INF)
                cout << "-";
            else if (x == 1)
                cout << "W";
            else cout << "B";                   // x == -1
        }
        cout << endl;
    }

    board_printed = true;
}

bool dfs(int i, int j, int N, int M) {
    if (i <= 0 || i == N || j <= 0 || j == M || G[i][j] == INF)
        return false;
    
    bool can_place = true;
    for (pair<int,int>& move : moves) {
        int n_i = i + move.first;
        int n_j = j + move.second;
        if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M) {
            if (G[n_i][n_j] == 1)                       // placing white
                can_place = false;
        }
    }

    if (can_place) {
        G[i][j] = 1;
        for (pair<int,int>& move : moves) {
            int n_i = i + move.first;
            int n_j = j + move.second;
            if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M && G[n_i][n_j] == 0)
                solution_found = solution_found || dfs(n_i, n_j, N, M);
                print_board(N, M);
        }
    }

    G[i][j] = 0;

    can_place = true;
    for (pair<int,int>& move : moves) {
        int n_i = i + move.first;
        int n_j = j + move.second;
        if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M) {
            if (G[n_i][n_j] == -1)                       // placing black
                can_place = false;
        }
    }

    if (can_place) {
        G[i][j] = -1;
        for (pair<int,int>& move : moves) {
            int n_i = i + move.first;
            int n_j = j + move.second;
            if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M && G[n_i][n_j] == 0)
                solution_found = solution_found || dfs(n_i, n_j, N, M);
                print_board(N, M);
        }
    }

    G[i][j] = 0;

    return solution_found;
}

void solve(int N, int M) {
    dfs(0, 0, N, M);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    G.assign(N, vector<int>(M, 0));

    char c;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == '-')
                G[i][j] = INF;
        }

    solve(N, M);
    
    return 0;
}