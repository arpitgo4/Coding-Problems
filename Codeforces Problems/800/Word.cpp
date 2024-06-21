// Word (https://codeforces.com/problemset/problem/59/A)
 
#include <iostream>
 
using namespace std;
 
// Time: O(N)
// Space: O(1) 

void string_upper(string& S) {
    int N = S.length();
    for (int i = 0; i < N; i++)
        S[i] = toupper(S[i]);
}

void string_lower(string& S) {
    int N = S.length();
    for (int i = 0; i < N; i++)
        S[i] = tolower(S[i]);
}

void solve(string& S) {
    int l_count = 0, u_count = 0;
    for (char c : S) {
        if (c == tolower(c))
            l_count++;
        else u_count++;
    }

    if (l_count >= u_count)
        string_lower(S);
    else string_upper(S);

    cout << S << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);
    
    return 0;
}