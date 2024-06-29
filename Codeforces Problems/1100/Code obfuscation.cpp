// Code obfuscation (https://codeforces.com/problemset/problem/765/B)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N)
// Space: O(1)
 
bool valid_code(string& S) {
    int N = S.length(), char_idx = -1;
    vector<int> table(26, 0);
    for (int i = 0; i < N; i++) {
        int curr_idx = S[i]-'a';
        if ((curr_idx - char_idx) > 1)
            return false;                                       // invalid code

        table[S[i]-'a']++;
        char_idx = max(char_idx, curr_idx);
    }

    int count = 0;
    for (int i = 0; i < 26 && table[i] > 0; i++)
        count += table[i];

    return count == N;
}

void solve(string& S) {
    bool valid = valid_code(S);
    cout << (valid ? "YES" : "NO") << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);
    
    return 0;
}