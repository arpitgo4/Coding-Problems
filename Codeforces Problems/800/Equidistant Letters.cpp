// Equidistant Letters (https://codeforces.com/problemset/problem/1626/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(string& S) {
    sort(S.begin(), S.end());
    cout << S << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        string S;
        cin >> S;
        
        solve(S);
    }
    
    return 0;
}