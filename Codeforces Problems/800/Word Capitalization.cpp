// Word Capitalization (https://codeforces.com/problemset/problem/281/A)
 
#include <iostream>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S) {
    S[0] = toupper(S[0]);
    cout << S << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);    
    
    return 0;
}