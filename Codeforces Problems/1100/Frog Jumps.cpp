// Frog Jumps (https://codeforces.com/problemset/problem/1324/C)
 
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S) {
    int N = S.length();

    int max_len = 0, last_r_idx = N-1;
    for (int i = N-2; i >= 0; i--) {
        if (S[i] == 'R') {
            max_len = max(max_len, last_r_idx-i);
            last_r_idx = i;
        }
    }

    cout << max_len << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        string S;
        cin >> S;
    
        S = 'R' + S + 'R';
        solve(S);
    }
    
    return 0;
}