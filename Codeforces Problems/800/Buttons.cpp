// Buttons (https://codeforces.com/problemset/problem/1858/A)
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
/**
 * Count number of moves which can be made
 * if count == even => Anna wins
 * else count == odd => Katie wins
 */

void solve(int a, int b, int c) {
    if (c % 2 == 0)                                             // Anna's move
        cout << (a > b ? "First" : "Second") << endl;
    else                                                        // Katie's move
        cout << (b > a ? "Second" : "First") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
    
        solve(a, b, c);
    }
    
    return 0;
}