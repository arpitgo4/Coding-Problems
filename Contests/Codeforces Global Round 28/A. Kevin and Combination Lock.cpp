// A. Kevin and Combination Lock (https://codeforces.com/contest/2048/problem/A)
 
#include <iostream>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
/**
 * If x is multiple of 33 (11, 3) we can reduce it to zero by
 * subtracting (33, 11, 3) from it.
 * 
 * 33 == 0 (substract 11, 3 times)
 * 33 == 0 (substract 3, 11 times)
 * 
 * 33, 330, 3300, 33000...
 * 
 * (x - 33) % 100 == 0
 */

void solve(int x) {
    cout << (x % 33 == 0 ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int x;
        cin >> x;
    
        solve(x);
    }
    
    return 0;
}