// NAJPF - Pattern Find (https://www.spoj.com/problems/NAJPF/)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N + M)
// Space: O(M)
 
vector<int> pi;

/**
 * KMP algorithm / Prefix Function / Border Function
 * 
 * pi[i] => denotes the longest proper prefix of the substring[0,i]
 *          that is also the suffix of the substring[0,i]
 */
void pi_function(string S, int N) {
    pi.assign(N, 0);
    for (int i = 1; i < N; i++) {
        int j = pi[i-1];
        while (j > 0 && S[i] != S[j])
            j = pi[j-1];
        if (S[i] == S[j])
            j++;
        pi[i] = j;
    }
}

void solve(string& S, string& P) {
    int M = P.length();
    pi_function(P + '$', M);

    int count = 0;
    vector<int> pos;

    int N = S.length();
    int j = (S[0] == P[0] ? 1 : 0);
    for (int i = 1; i < N; i++) {
        while (j > 0 && S[i] != P[j])
            j = pi[j-1];
        if (S[i] == P[j])
            j++;

        if (j == M) {
            count++;
            pos.push_back(i-M+2);
        }
    }

    if (count == 0) {
        cout << "Not Found" << endl;
    } else {
        cout << count << endl;
        for (int p : pos)
            cout << p << " ";
        cout << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        string S, P;
        cin >> S >> P;

        solve(S, P);
        cout << endl;
    }
    
    return 0;
}