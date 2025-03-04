// dancerecital (https://open.kattis.com/problems/dancerecital)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <unordered_set>
 
using namespace std;
 
// Time: O(N!)
// Space: O(N)
 
using matrix_t = vector<vector<int>>;

const int INF = INT_MAX;

int countQuickChanges(
    vector<int>& routine_indexes, 
    matrix_t& change_cnt, 
    int routine_cnt
) {
    int quick_change_cnt = 0;
    for (int i = 0; i < routine_cnt-1; i++) {
        int curr_idx = routine_indexes[i];
        int next_idx = routine_indexes[i+1];
        
        quick_change_cnt += change_cnt[curr_idx][next_idx];
    }

    return quick_change_cnt;
}

void precalculateChangeCountForPairs(
    vector<string>& routines,
    int routine_cnt,
    matrix_t& change_cnt
) {
    for (int i = 0; i < routine_cnt; i++) {
        for (int j = 0; j < routine_cnt; j++) {
            if (change_cnt[i][j] != -1)
                continue;

            int cnt = 0;
            unordered_set<char> curr_char_set(routines[i].begin(), routines[i].end());
            for (char c : routines[j]) {
                if (curr_char_set.find(c) != curr_char_set.end()) {
                    cnt++;
                }
            }

            change_cnt[i][j] = change_cnt[j][i] = cnt;
        }
    }
}

void solve(vector<string>& routines, int routine_cnt) {
    vector<int> routine_indexes(routine_cnt);
    iota(routine_indexes.begin(), routine_indexes.end(), 0);

    matrix_t change_cnt(routine_cnt, vector<int>(routine_cnt, -1));
    precalculateChangeCountForPairs(routines, routine_cnt, change_cnt);

    int min_quick_change_cnt = INF;
    do {
        int quick_change_cnt = countQuickChanges(routine_indexes, change_cnt, routine_cnt);
        min_quick_change_cnt = min(min_quick_change_cnt, quick_change_cnt);
    } while (next_permutation(routine_indexes.begin(), routine_indexes.end()));

    cout << min_quick_change_cnt << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int routine_cnt;
    cin >> routine_cnt;
    
    vector<string> routines(routine_cnt);
    for (int i = 0; i < routine_cnt; i++) {
        cin >> routines[i];
    }

    solve(routines, routine_cnt);
    
    return 0;
}