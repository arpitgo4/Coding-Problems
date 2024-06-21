// Fake News (easy) (https://codeforces.com/problemset/problem/802/G)
 
#include <iostream>
#include <vector>

using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S) {
    int N = S.length();

    string T = "heidi";
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == T[j])
            j++;
    }

    if (j == T.length())
        cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);
    
    return 0;
}