// My First Sorting Problem (https://codeforces.com/problemset/problem/1971/A)
 
#include <iostream>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(int x, int y) {
    cout << min(x, y) << " " << max(x, y) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int x, y;
        cin >> x >> y;
        
        solve(x, y);
    }
    
    return 0;
}