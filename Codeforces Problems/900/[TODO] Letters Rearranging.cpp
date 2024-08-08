// Letters Rearranging (https://codeforces.com/problemset/problem/1093/B)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S) {
    int N = S.length();

    vector<int> table(26, 0);
    for (char c : S)
        table[c-'a']++;

    int odd_count = 0, even_count = 0;
    for (int v : table)
        if (v > 0)
            v % 2 == 0 ? even_count++ : odd_count++;

    cout << "Odd Count: " << odd_count << endl;
    if (odd_count <= 1) {
        cout << -1 << endl;
        return;
    }

    sort(S.begin(), S.end());
    cout << S << endl;
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