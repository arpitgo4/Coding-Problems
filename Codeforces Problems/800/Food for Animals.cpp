// Food for Animals (https://codeforces.com/problemset/problem/1675/A)
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(int a, int b, int c, int x, int y) {
    x -= min(x, a);
    y -= min(y, b);

    if (x + y <= c)
        cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
    
        solve(a, b, c, x, y);
    }
    
    return 0;
}