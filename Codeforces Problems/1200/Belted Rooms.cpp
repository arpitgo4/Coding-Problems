// Belted Rooms (https://codeforces.com/problemset/problem/1428/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
/**
 * Interesting logical problem
 * 
 * Looks like problem related to Strongly Connected Components
 * but it's simpler and can be solved with easy logics.
 */

// Time: O(N)
// Space: O(N)

void solve(string& S, int N) {
    bool clockwise = true;
    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == '<')
            clockwise = false;
    }

    bool anti_clockwise = true;
    for (int i = N-1; i >= 0; i--) {
        char c = S[i];
        int u = i, v = i-1;
        if (v == -1)
            v = N-1;
        if (c == '>')
            anti_clockwise = false;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        char c = S[i];
        int u = i, v = i-1;
        if (v == -1)
            v = N-1;
        
        if (S[u] == '-' || S[v] == '-')
            count++;
    }

    if (clockwise || anti_clockwise)
        cout << N << endl;
    else cout << count << endl;
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