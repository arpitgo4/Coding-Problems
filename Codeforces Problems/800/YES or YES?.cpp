// YES or YES? (https://codeforces.com/problemset/problem/1703/A)
 
#include <iostream>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
void solve(string& S) {
    bool cond1 = S[0] == 'Y' || S[0] == 'y';
    bool cond2 = S[1] == 'E' || S[1] == 'e';
    bool cond3 = S[2] == 'S' || S[2] == 's';

    bool match = cond1 && cond2 && cond3;

    cout << (match ? "YES" : "NO") << endl;
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