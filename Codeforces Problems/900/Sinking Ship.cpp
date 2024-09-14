// Sinking Ship (https://codeforces.com/problemset/problem/63/A)
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
const string WOMAN      = "woman",
             MAN        = "man",
             CAPTAIN    = "captain",
             RAT        = "rat",
             CHILD      = "child";

void solve(vector<string>& A, vector<string>& S, int N) {
    vector<int> P(N);
    for (int i = 0; i < N; i++)
        P[i] = i;

    sort(P.begin(), P.end(), [&](const int i, const int j) {
        if (S[i] == CAPTAIN)
            return false;
        if (S[j] == CAPTAIN)
            return true;
        if (S[i] == RAT) {
            if (S[j] == RAT)
                return i < j;
            return true;
        }
        if (S[i] == WOMAN || S[i] == CHILD) {
            if (S[j] == WOMAN || S[j] == CHILD)
                return i < j;
            return true;                                        // if S[j] == MAN
        }
        if (S[i] == MAN) {
            if (S[j] == MAN)
                return i < j;
            return false;                                       // if S[j] == WOMAN || S[j] == CHILD
        }
    });

    for (int p : P)
        cout << A[p] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<string> A(N), S(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> S[i];

    solve(A, S, N);
    
    return 0;
}