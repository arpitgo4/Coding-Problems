// Hit the Lottery (https://codeforces.com/problemset/problem/996/A)

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

vector<int> dp;
vector<int> bills{1, 5, 10, 20, 100};

int dfs(int x) {
    if (x == 0)
        return 0;
    if (dp[x] != -1)
        return dp[x];

    int min_bills = INT_MAX;
    for (int bill : bills) {
        if (x-bill >= 0)
            min_bills = min(min_bills, 1 + dfs(x-bill));
    }
    
    return dp[x] = min_bills;
}

void solve(int N) {
    dp.assign(N+1, -1);
    int count = dfs(N);

    cout << count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    solve(N);        
    
    return 0;
}