// Short Substrings (https://codeforces.com/problemset/problem/1367/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S) {
    int N = S.length();
    string T = "";
    for (int i = 0; i < N; i+=2)
        T += S[i];
    T += S[N-1];

    cout << T << endl;
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