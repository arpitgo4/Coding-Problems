// Fair Division (https://codeforces.com/problemset/problem/1472/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N^2)
// Space: O(N^2)

vector<vector<int>> dp;

bool dfs(int i, int sum, vector<int>& A, int N, int total_sum) {
    if (i == N)
        return (2*sum) == total_sum;
    if (dp[i][sum] != -1)
        return dp[i][sum];

    return dp[i][sum] = dfs(i+1, sum + A[i], A, N, total_sum) ||
            dfs(i+1, sum, A, N, total_sum); 
}

void solve(vector<int>& A, int N) {
    int set_sum = 0;
    for (int a : A)
        set_sum += a;

    dp.assign(N+1, vector<int>(set_sum, -1));
    bool can_do = dfs(0, 0, A, N, set_sum);
    cout << (can_do ? "YES" : "NO") << endl;
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