// Fibonacci army (https://codeforces.com/problemset/problem/72/G)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(int x) {
    vector<int> dp(x+1, 1);
    for (int i = 2; i <= x; i++) 
        dp[i] = dp[i-1] + dp[i-2];

    cout << dp[x] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    solve(N);
    
    return 0;
}