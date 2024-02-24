// Stylish clothes (https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
 
// N` = N1 + N2 + N3 + N4
// Time: O(N`logN`)
// Space: O(1)
 
void solve(vector<vector<int>>& clothes, int caps_N, int shirts_N, int pants_N, int boots_N) {
    for (int i = 0; i < 4; i++) {
        clothes[i].push_back(INT_MAX);                      // padding for loop
        sort(clothes[i].begin(), clothes[i].end());
    }

    int min_diff = INT_MAX;
    int i = 0, j = 0, k = 0, q = 0;
    int res_i, res_j, res_k, res_q;
    while (i < caps_N || j < shirts_N || k < pants_N || q < boots_N) {

        int min_e = min({ clothes[0][i], clothes[1][j], clothes[2][k], clothes[3][q] });
        int max_e = max({ clothes[0][i], clothes[1][j], clothes[2][k], clothes[3][q] });

        if (min_diff > max_e-min_e) {
            min_diff = max_e - min_e;
            res_i = clothes[0][i];
            res_j = clothes[1][j]; 
            res_k = clothes[2][k]; 
            res_q = clothes[3][q];
        }

        if (min_e == clothes[0][i]) i++;
        if (min_e == clothes[1][j]) j++;
        if (min_e == clothes[2][k]) k++;
        if (min_e == clothes[3][q]) q++;
    }

    cout << res_i << " " << res_j << " " << res_k << " " << res_q << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> clothes(4, vector<int>());

    int N, x;
    for (int i = 0; i < 4; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> x;
            clothes[i].push_back(x);
        }    
    }

    solve(clothes, clothes[0].size(), clothes[1].size(), clothes[2].size(), clothes[3].size());
    
    return 0;
}