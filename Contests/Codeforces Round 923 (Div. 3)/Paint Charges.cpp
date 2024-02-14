// Paint Charges (https://codeforces.com/contest/1927/problem/G)
 
#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N * 2^MAX_N)
// Space: O(N * 2^MAX_N)
 
// DP state: (cell_idx, [cells_state])
// cell_state: (0 | 1)

const int MAX_N = 101;
vector<unordered_map<string,int>> dp;

bitset<MAX_N> set_bits(bitset<MAX_N>& mask, int l, int h) {
    int w_size = h-l+1;
    bitset<MAX_N> submask = ((1<<w_size)-1);
    bitset<MAX_N> new_mask = mask | (submask << l);

    return new_mask;
}

int dfs(int i, bitset<MAX_N>& mask, vector<int>& A, int N) {
    if (mask.count() == N)
        return 0;
    if (i == N)
        return INT_MAX;
    if (dp[i].find(mask.to_string()) != dp[i].end())
        return dp[i][mask.to_string()];

    int left_idx = max(i-A[i]+1, 0);                                // max(i-A[i]+1, 0) to i inclusive
    auto new_mask = set_bits(mask, left_idx, i);

    int left = dfs(i+1, new_mask, A, N);
    left += (left == INT_MAX ? 0 : 1);

    int right_idx = min(i+A[i]-1, N-1);                             // i to min(i+A[i]-1, N-1) inclusive
    new_mask = set_bits(mask, i, right_idx);

    int right = dfs(i+1, new_mask, A, N);
    right += (right == INT_MAX ? 0 : 1);

    int pass = dfs(i+1, mask, A, N);

    return dp[i][mask.to_string()] = min({ left, right, pass });
}

void solve(vector<int>& A, int N) {
    dp.assign(N, unordered_map<string,int>());

    bitset<MAX_N> mask(0);
    int min_cost = dfs(0, mask, A, N);

    cout << min_cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    int N;
    while (T--) {
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        solve(A, N);
    }
    
    return 0;
}