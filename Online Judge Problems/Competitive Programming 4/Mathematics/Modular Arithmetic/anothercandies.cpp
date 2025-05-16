// anothercandies (https://open.kattis.com/problems/anothercandies)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
using ll = long long;

void solve(vector<ll>& candy_cnt, int children_cnt) {
    ll candy_sum = 0;
    for (ll cnt : candy_cnt) {
        candy_sum = (candy_sum + cnt) % children_cnt;
    }
    
    cout << (candy_sum == 0 ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cnt;
    cin >> test_cnt;
    
    while (test_cnt > 0) {
        int children_cnt;
        cin >> children_cnt;

        vector<ll> candy_cnt(children_cnt);
        for (int i = 0; i < children_cnt; i++) {
            cin >> candy_cnt[i];
        }

        solve(candy_cnt, children_cnt);

        test_cnt--;
    }
    
    return 0;
}