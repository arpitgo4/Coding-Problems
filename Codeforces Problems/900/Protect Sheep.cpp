// Protect Sheep (https://codeforces.com/problemset/problem/948/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * M)
// Space: O(N * M)

const vector<pair<int,int>> moves{
    { -1, 0 },                  // up
    { 1, 0 },                   // down
    { 0, -1 },                  // left
    { 0, 1 }                    // right
};

void solve(vector<vector<char>>& farm, int row_cnt, int col_cnt) {
    bool can_protect = true;
    for (int i = 0; i < row_cnt; i++) {
        for (int j = 0; j < col_cnt; j++) {
            if (farm[i][j] == 'S') {
                for (auto& move : moves) {
                    auto& [ diff_i, diff_j ] = move;
                    int next_i = i + diff_i;
                    int next_j = j + diff_j;
                    if (next_i >= 0 && next_i < row_cnt && 
                            next_j >= 0 && next_j < col_cnt) {
                        
                        if (farm[next_i][next_j] == 'W')
                            can_protect = false;

                        if (farm[next_i][next_j] == '.')
                            farm[next_i][next_j] = 'D';
                    }
                }
            }
        }
    }

    cout << (can_protect ? "YES" : "NO") << endl;
    if (can_protect) {
        for (int i = 0; i < row_cnt; i++) {
            for (int j = 0; j < col_cnt; j++) {
                cout << farm[i][j];        
            }
            cout << endl;
        }
        cout << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int row_cnt, col_cnt;
    cin >> row_cnt >> col_cnt;
    
    vector<vector<char>> farm(row_cnt, vector<char>(col_cnt));
    for (int i = 0; i < row_cnt; i++) {
        for (int j = 0; j < col_cnt; j++) {
            cin >> farm[i][j];
        }
    }

    solve(farm, row_cnt, col_cnt);
    
    return 0;
}