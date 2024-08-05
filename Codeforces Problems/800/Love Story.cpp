// Love Story (https://codeforces.com/problemset/problem/1829/A)
 
#include <iostream>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(string& S) {
    string T = "codeforces";
    int count = 0;
    for (int i = 0; i < 10; i++)
        if (S[i] != T[i])
            count++;

    cout << count << endl;
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