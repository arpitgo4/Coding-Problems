// combinations (https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=305)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N * K)
// Space: O(N * K)
 
using ll = long long;

ll binomialCoefficient(ll n, ll k, vector<vector<ll>>& dp) {
    if (k == 0 || k == n)
        return 1;
    if (dp[n][k] != -1)
        return dp[n][k];
    if (k > n-k)
        k = n-k;
    
    int included = binomialCoefficient(n-1, k-1, dp);
    int excluded = binomialCoefficient(n-1, k, dp);

    return dp[n][k] = included + excluded;
}

void solve(ll obj_cnt, ll choose_cnt) {
    vector<vector<ll>> dp(obj_cnt+1, vector<ll>(choose_cnt+1, -1));

    ll coefficient = binomialCoefficient(obj_cnt, choose_cnt, dp);
    cout << obj_cnt << " things taken " << choose_cnt << " at a time is ";
    cout << coefficient << " exactly." << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       
    ll obj_cnt, choose_cnt;
    cin >> obj_cnt >> choose_cnt;

    while (obj_cnt > 0 && choose_cnt > 0) {
        solve(obj_cnt, choose_cnt);
        
        cin >> obj_cnt >> choose_cnt;
    }
    
    return 0;
}