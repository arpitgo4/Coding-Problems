// NHAY - A Needle in the Haystack (https://www.spoj.com/problems/NHAY/)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(N + M)
// Space: O(M)
  
vector<int> pi;

void pi_function(string& S) {
    int N = S.length();
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

void solve(int M, string& needle, string& haystack) {
    string str = needle + '$';
    pi_function(str);

    bool found = false;
    int N = haystack.length(), prev_pi = 0;
    for (int i = 0; i < N; i++) {
        if (needle[prev_pi] == haystack[i])
            prev_pi++;
        else {
            while (prev_pi > 0 && needle[prev_pi] != haystack[i])
                prev_pi = pi[prev_pi-1];
            if (needle[prev_pi] == haystack[i])
                prev_pi++;
        }

        if (prev_pi == M) {
            cout << (i-M+1) << endl;
            found = true;
        }
    }

    if (!found)
        cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M;
    string needle, haystack;
    while(cin >> M >> needle >> haystack)
        solve(M, needle, haystack);

    return 0;
}