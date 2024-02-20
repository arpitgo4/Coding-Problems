// Sum in Binary Tree (https://codeforces.com/problemset/problem/1843/C)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
// Time: O(N)
// Space: O(1)
 
void solve(ll u) {
    ll sum = 0;
    do {
        sum += u;
        u /= 2;
    } while (u != 0);

    cout << sum << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    ll u;
    while (T--) {
        cin >> u;

        solve(u);
    }   
    
    return 0;
}