// Yet Another Two Integers Problem (https://codeforces.com/problemset/problem/1409/A)
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(int a, int b) {
    int count = 0, diff = abs(a-b);
    for (int k = 10; k > 0; k--) {
        count += (diff / k);
        diff = (diff % k);
    }

    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int a, b;
        cin >> a >> b;
        
        solve(a, b);
    }
    
    return 0;
}