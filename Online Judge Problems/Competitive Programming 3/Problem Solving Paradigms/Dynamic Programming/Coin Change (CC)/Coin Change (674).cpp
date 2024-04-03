// Coin Change (674)
 
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
// Time: O(N * 5) ~ O(N)
// Space: O(N * 5) ~ O(N)
 
typedef long long ll;
 
const int MAX_N = 7489;
vector<vector<ll>> dp(MAX_N+1, vector<ll>(5, -1));

vector<int> coins{
    50, 25, 10, 5, 1 
};

ll dfs(int N, int c_idx) {
    if (N == 0)
        return 1;
    if (N < 0)
        return 0;
    if (dp[N][c_idx] != -1)
        return dp[N][c_idx];

    ll count = 0;
    for (int i = c_idx; i < 5; i++) {
        int coin = coins[i];
        count += dfs(N-coin, i);
    }

    return dp[N][c_idx] = count;
}

ll solve(int N) {
    ll count = dfs(N, 0);
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

        int N = stoi(line);
        ll count = solve(N);
        cout << count << endl;
    }
    
    return 0;
}