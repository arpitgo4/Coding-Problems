// X Axis (https://codeforces.com/problemset/problem/1986/A)
 
#include <iostream>
#include <cmath>
#include <climits>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(int x1, int x2, int x3) {
    int min_dist = INT_MAX;
    for (int i = 1; i <= 10; i++)
        min_dist = min(min_dist, abs(x1-i) + abs(x2-i) + abs(x3-i));

    cout << min_dist << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
    
        solve(x1, x2, x3);
    }
    
    return 0;
}