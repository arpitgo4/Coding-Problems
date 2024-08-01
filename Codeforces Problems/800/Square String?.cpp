// Square String? (https://codeforces.com/problemset/problem/1619/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S) {
    int N = S.length();
    if (N % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    
    int mid = N/2;
    for (int i = 0; i < mid; i++) {
        if (S[i] != S[mid+i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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