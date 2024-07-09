// Thorns and Coins (https://codeforces.com/problemset/problem/1932/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

vector<int> dp;

int dfs(int i, string& S, int N) {
    if (i >= N || S[i] == '*')
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int count = S[i] == '@' ? 1 : 0;

    return dp[i] = count + max(
        dfs(i+1, S, N), 
        dfs(i+2, S, N)
    );
}

void solve(string& S, int N) {
    dp.assign(N, -1);

    int max_coins = dfs(0, S, N);
    cout << max_coins << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string S;
        cin >> S;

        solve(S, N);
    }
    
    return 0;
}