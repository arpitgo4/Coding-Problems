// Two Teams Composing (https://codeforces.com/problemset/problem/1335/C)
 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

/**
 * Test case #1: 1 1 3
 * max_freq = 2, dist_cnt = 2, result => 1
 * 
 * Test case #2: 1 2
 * max_freq = 1, dist_cnt = 2, result => 1 
 * 
 * Test case #3: 1 1
 * max_freq = 2, dist_cnt = 1, result => 1
 * 
 * Test case #4: 2 1 5 4 3
 * max_freq = 1, dist_cnt = 5, result => 1
 */

void solve(vector<int>& A, int N) {
    int max_freq = 0;
    unordered_map<int,int> uMap;
    for (int a : A) {
        uMap[a]++;
        max_freq = max(max_freq, uMap[a]);
    }

    int dist_cnt = uMap.size();                     // max_freq element is also included in this count

    int max_team_sz = min(max_freq-1, dist_cnt);
    if (max_freq < dist_cnt) {
        max_team_sz = min(max_freq, dist_cnt-1);
    }
 
    cout << max_team_sz << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
    
        solve(A, N);
    }
    
    return 0;
}