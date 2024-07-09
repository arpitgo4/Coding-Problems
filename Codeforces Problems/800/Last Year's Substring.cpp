// Last Year's Substring (https://codeforces.com/problemset/problem/1462/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(1)
// Space: O(1)

void solve(string& S, int N) {
    string pattern = "2020";
    for (int i = 0; i <= 4; i++) {
        if (S.substr(0, i) + S.substr(N-4+i, 4-i) == pattern) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string S;
        cin >> S;

        solve(S, N);
    }
    
    return 0;
}