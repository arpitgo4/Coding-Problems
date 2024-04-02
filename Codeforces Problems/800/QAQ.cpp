// QAQ (https://codeforces.com/problemset/problem/894/A)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(N^2)
// Space: O(N * M) ~ O(N * 3) ~ O(N)
 
vector<vector<int>> dp;

const int M = 3;
string T = "QAQ";

int dfs(int i, int j, string& S, int N) {
    if (i == N)
        return (j == M ? 1 : 0);
    if (j == M)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int count = 0;
    for (int idx = i; idx < N; idx++) {
        if (S[idx] == T[j])
            count += dfs(idx+1, j+1, S, N);
    }

    return dp[i][j] = count;
}

void solve(string& S) {
    int N = S.length();

    dp.assign(N, vector<int>(M, -1));

    int count = dfs(0, 0, S, N);
    cout << count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);   
    
    return 0;
}