// Districts Connection (https://codeforces.com/problemset/problem/1433/D)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N^2)
// Space: O(N)

/**
 * Need to find a permutation that satisfies problem's constraints! 
 * Time: O(N!)
 * This will TLE!
 * 
 * We can use Bitmask DP here.
 * Time: O(2^N)
 * But, this will TLE!
 * 
 * Pick a district and then pick next not-similar district
 * This hints towards a backtracking algorithm with a dynamic
 * data-structure
 * 
 * Take a greedy approach or ad-hoc problem solving will do this
 * in linear/quasi-linear time
*/

vector<int> dp, P;

int dfs(int i, vector<int>& A, int N) {
    if (i == N)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    
    int can_build = 0;
    for (int j = i+1; j < N; j++) {
        if (A[i] != A[j]) {
            can_build |= dfs(j, A, N);
            if (can_build) {
                P[j] = i;
                break;
            }
        }
    }

    return dp[i] = can_build;
}

void solve(vector<int>& A, int N) {
    dp.assign(N, -1);
    P.assign(N, -1);

    int can_build = dfs(0, A, N);

    if (!can_build) {
        cout << "NO" << endl;
        return;
    } else cout << "YES" << endl;

    int curr = N-1;
    vector<pair<int,int>> path;
    while (curr != -1) {
        path.push_back({ curr, P[curr] });      // fix for when P[curr] == -1
        curr = P[curr];
    }

    for (auto& p : path)
        cout << p.first << " " << p.second << endl;
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