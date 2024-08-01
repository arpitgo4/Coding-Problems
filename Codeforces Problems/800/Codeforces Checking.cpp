// Codeforces Checking (https://codeforces.com/problemset/problem/1791/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)
 
vector<int> table(26, 0);

void init() {
    string word = "codeforces";
    for (char c : word)
        table[c-'a']++;
}

void solve(char c) {
    cout << (table[c-'a'] > 0 ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    init();
    
    while (T--) {
        char c;
        cin >> c;
    
        solve(c);
    }
    
    return 0;
}