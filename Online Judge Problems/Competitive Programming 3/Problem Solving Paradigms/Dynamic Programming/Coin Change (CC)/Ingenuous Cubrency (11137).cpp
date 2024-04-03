// Ingenuous Cubrency (11137)
 
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
// Time: O(N * 21) ~ O(N)
// Space: O(N * 21) ~ O(N)

typedef long long ll;
 
const int MAX_N = 1e4;
vector<vector<ll>> dp(MAX_N+1, vector<ll>(22, -1));

ll dfs(int N, int coin_idx) {
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    if (dp[N][coin_idx] != -1)
        return dp[N][coin_idx];

    ll count = 0;
    for (int i = coin_idx; i <= 21; i++) {
        ll coin = i * i * i;
        count += dfs(N-coin, i);
    }
    
    return dp[N][coin_idx] = count;
}

ll solve(int N) {
    ll count = dfs(N, 1);
    return count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string line;
    while (true) {
        getline(cin, line);
        if (line.empty())
            break;
        
        ll count = solve(stoi(line));
        cout << count << endl;
    }
    
    return 0;
}