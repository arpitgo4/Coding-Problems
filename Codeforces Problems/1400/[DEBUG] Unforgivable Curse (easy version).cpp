// Unforgivable Curse (easy version) (https://codeforces.com/problemset/problem/1800/E1)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S, string& T, int N, int K) {
    for (int i = 0; i < N; i++) {
        if (i-K < 0 && i+K >= N && S[i] != T[i]) {
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
        int N, K;
        cin >> N >> K;
        
        string S, T;
        cin >> S >> T;
    
        solve(S, T, N, K);
    }
    
    return 0;
}