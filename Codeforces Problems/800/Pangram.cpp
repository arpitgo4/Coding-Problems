// Pangram (https://codeforces.com/problemset/problem/520/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S, int N) {
    vector<bool> found(26, false);
    for (char c : S)
        found[tolower(c)-'a'] = true;

    for (bool f : found)
        if (f == false) {
            cout << "NO" << endl;
            return;
        }

    cout << "YES" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    string S;
    cin >> S;

    solve(S, N);
    
    return 0;
}