// Decoding (https://codeforces.com/problemset/problem/746/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(string& S, int N) {
    // if N % 2 == 1, go left-right
    // else, go right-left

    string decoded = "";
    if (N % 2 == 0) {
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0)
                decoded = S[i] + decoded;
            else decoded += S[i];
        }
    } else {
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0)
                decoded += S[i];
            else decoded = S[i] + decoded;
        }
    }
    
    cout << decoded << endl;
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