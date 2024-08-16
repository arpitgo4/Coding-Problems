// Coins (https://atcoder.jp/contests/dp/tasks/dp_i)
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>
 
using namespace std;
 
// Time: O(N^2)
// Space: O(N^2)
 
// N coins
// N/2 + 1 -> heads
// N/2 - 1 -> tails

#define INF DOUBLE_MAX

vector<vector<double>> dp;

double dfs(int i, int h_count, vector<double>& A, int N) {
    if (i == N)
        return (h_count > (N-h_count) ? 1.0 : 0.0);
    if (dp[i][h_count] != -1.0)
        return dp[i][h_count];

    double a = A[i] * dfs(i+1, h_count+1, A, N);
    double b = (1-A[i]) * dfs(i+1, h_count, A, N);
    
    return dp[i][h_count] = a + b;
}

void solve(vector<double>& A, int N) {
    dp.assign(N, vector<double>(N, -1.0));
    double chances = dfs(0, 0, A, N);

    cout << setprecision(10) << chances << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<double> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    solve(A, N);
    
    return 0;
}