// Binary Cut (https://codeforces.com/problemset/problem/1971/D)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
/**
 * Problem can be parapharesed as,
 * find the count of largest already sorted 
 * pieces from the given string
 */

void solve(string& S) {
    int N = S.length();

    int count = 0;
    for (int i = 1; i < N; i++) {
        if (S[i-1] > S[i]) {
            count++;
        }
    }

    cout << (count+1) << endl;
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