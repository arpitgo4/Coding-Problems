// Distinct Split (https://codeforces.com/problemset/problem/1791/D)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)
 
void solve(string& S, int N) {
    vector<int> PF_L(N, 0), PF_R(N, 0);
    vector<int> table(26, 0);

    table[S[0]-'a'] = 1;
    PF_L[0] = 1;
    for (int i = 1; i < N; i++) {
        PF_L[i] = PF_L[i-1];
        if (table[S[i]-'a'] == 0)
            PF_L[i]++;
        
        table[S[i]-'a']++;
    }

    table.assign(26, 0);
    table[S[N-1]-'a'] = 1;
    PF_R[N-1] = 1;
    for (int i = N-2; i >= 0; i--) {
        PF_R[i] = PF_R[i+1];
        if (table[S[i]-'a'] == 0)
            PF_R[i]++;
        
        table[S[i]-'a']++;
    }

    int max_val = 0;
    int left, right;
    for (int i = 1; i < N; i++) {
        left = PF_L[i-1];
        right = PF_R[i];

        max_val = max(max_val, left + right);
    }

    cout << max_val << endl;
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