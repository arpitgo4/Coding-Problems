// Two Vessels (https://codeforces.com/problemset/problem/1872/A)
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(double a, double b, double c) {
    double mid = (a + b) / 2;
    double diff = abs(a-mid);

    int count = ceil(diff / c);
    cout << count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        double a, b, c;
        cin >> a >> b >> c;
    
        solve(a, b, c);
    }
    
    return 0;
}