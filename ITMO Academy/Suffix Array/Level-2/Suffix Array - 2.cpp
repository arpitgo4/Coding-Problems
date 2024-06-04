// Suffix Array - 2 (https://codeforces.com/edu/course/2/lesson/2/2/practice/contest/269103/problem/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(NlogN)
// Space: O(N)
 
vector<int> P, C;
const int ALPHABET = 256;

void sort_cyclic_shifts(string& S) {
    int N = S.length();
    P.assign(N, 0);
    C.assign(N, 0);
    vector<int> cnt(max(ALPHABET, N), 0);
    for (int i = 0; i < N; i++)
        cnt[S[i]]++;
    for (int i = 1; i < ALPHABET; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < N; i++)
        P[--cnt[S[i]]] = i;
    C[P[0]] = 0;
    int classes = 1;
    for (int i = 1; i < N; i++) {
        if (S[P[i]] != S[P[i-1]])
            classes++;
        C[P[i]] = classes - 1;
    }

    vector<int> PN(N), CN(N);
    for (int h = 0; (1 << h) < N; ++h) {
        for (int i = 0; i < N; i++) {
            PN[i] = P[i] - (1 << h);
            if (PN[i] < 0)
                PN[i] += N;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < N; i++)
            cnt[C[PN[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = N-1; i >= 0; i--)
            P[--cnt[C[PN[i]]]] = PN[i];
        CN[P[0]] = 0;
        classes = 1;
        for (int i = 1; i < N; i++) {
            pair<int, int> cur = {C[P[i]], C[(P[i] + (1 << h)) % N]};
            pair<int, int> prev = {C[P[i-1]], C[(P[i-1] + (1 << h)) % N]};
            if (cur.first != prev.first || cur.second != prev.second)
                ++classes;
            CN[P[i]] = classes - 1;
        }
        C = CN;
    }
}

void solve(string& S) {
    int N = S.length();
    string str = S + "$";
    sort_cyclic_shifts(str);

    for (int suff_idx : P)
        cout << suff_idx << " ";
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;

    solve(S);
    
    return 0;
}