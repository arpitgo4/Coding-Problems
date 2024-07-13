// The New Year: Meeting Friends (https://codeforces.com/problemset/problem/723/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(int a, int b, int c) {
    int min_dist = max(a, max(b, c)) - min(a, min(b, c));
    cout << min_dist << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;

    solve(a, b, c);
    
    return 0;
}