// Translation (https://codeforces.com/problemset/problem/41/A)
 
#include <iostream>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S, string& T) {
    if (S.length() != T.length()) {
        cout << "NO" << endl;
        return;
    }

    int N = S.length();
    bool matches = true;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[N-i-1]) {
            matches = false;
            break;
        }
    }

    cout << (matches ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S, T;
    cin >> S >> T;

    solve(S, T);
    
    return 0;
}