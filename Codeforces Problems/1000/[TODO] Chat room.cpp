// Chat room (https://codeforces.com/problemset/problem/58/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
void solve(string& S) {
    int N = S.length();

    string dedup = "" + S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i-1])
            continue;
        dedup.push_back(S[i]);
    }

    cout << dedup << endl;

    S = dedup;

    string P = "hello";
    int j = 0, M = P.length();
    for (int i = 0; i < N; i++) {
        if (S[i] == S[j]) {
            j++;
            if (j == M) {
                cout << "YES" << endl;
                return;
            }
        }
        else {
            j = 0;
        }
    }

    cout << "NO" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);
    
    return 0;
}